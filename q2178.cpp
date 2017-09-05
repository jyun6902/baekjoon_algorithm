#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;

int maps[102][102] = {};
bool visit[102][102] = {};
int main()
{
	int n, m = 0, cnt = 1;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	deque <pair<int, int>> dq;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%1d", &maps[i][j]);
	}
	dq.push_back({ 1,1 });

	while (!dq.empty())
	{
		int t = dq.size();
		for (int i = 0; i < t; i++)
		{
			int x = dq.front().first;
			int y = dq.front().second;
			dq.pop_front();
			if (x == n && y == m)
			{
				cout << cnt <<endl;
				return 0;
			}

			for (int k = 0; k < 4; k++)
			{
				int n_x = x + dx[k];
				int n_y = y + dy[k];

				if (n_x < 1 || n_x > n || n_y < 1 || n_y > m || visit[n_x][n_y] == 1 || maps[n_x][n_y] == 0)
					continue;
				visit[n_x][n_y] = 1;
				dq.push_back({ n_x, n_y });
			}
		}
		cnt++;
	}
	return 0;
}