#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

int N = 0;
int maps[11][11] = {};
int visit[11][11] = {};
int min_result = 987654321;
deque <pair <int, int >> dq;
void cal(int x, int y, int cnt)
{
	if (cnt == 3)
	{
		deque <pair <int, int>> dq_cp;
		dq_cp = dq;
		int sum = 0;
		while (!dq_cp.empty())
		{
			int x = dq_cp.front().first;
			int y = dq_cp.front().second;
			dq_cp.pop_front();
			sum += maps[x - 1][y] + maps[x][y - 1] + maps[x][y] + maps[x][y + 1] + maps[x + 1][y];
		}
		if (sum < min_result)
			min_result = sum;
		return;
	}

	for (int i = x; i < N; i++)
	{
		for (int j = 2; j < N; j++)
		{
			if (visit[i - 1][j] == 0 && visit[i][j - 1] == 0 && visit[i][j] == 0 && visit[i][j + 1] == 0 && visit[i + 1][j] == 0 )
			{
				visit[i - 1][j] = visit[i][j - 1] = visit[i][j] = visit[i][j + 1] = visit[i + 1][j] = 1;
				dq.push_back({ i, j });
				cal(i, j, cnt + 1);
				visit[i - 1][j] = visit[i][j - 1] = visit[i][j] = visit[i][j + 1] = visit[i + 1][j] = 0;
				dq.pop_back();
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			scanf("%d", &maps[i][j]);
	}
	cal(2, 2, 0);
	printf("%d\n", min_result);
	return 0;
}