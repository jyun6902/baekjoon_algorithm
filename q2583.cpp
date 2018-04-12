#include <iostream>
#include <cstdio>
#include <deque>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int M, N, K = 0;
int maps[102][102] = {};
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int main()
{
	memset(maps, 0, sizeof(maps));
	scanf("%d %d %d", &M, &N, &K);
	vector <int > v;
	for (int cnt = 0; cnt < K; cnt++)
	{
		int x1, y1, x2, y2 = 0;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

		for (int i = x2 - 1; i >= x1; i--)
		{
			for (int j = y1; j < y2; j++)
			{
				maps[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (maps[i][j] == 0)
			{
				deque <pair <int, int >> dq;
				dq.push_back({ i,j });
				maps[i][j] = 1;
				int cnt = 0;
				while (!dq.empty())
				{
					int x = dq.front().first;
					int y = dq.front().second;
					dq.pop_front();
					cnt++;
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= M || ny < 0 || ny >= N || maps[nx][ny])
							continue;
						maps[nx][ny] = 1;
						dq.push_back({ nx, ny });
					}
				}
				if (cnt > 0)
					v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	return 0;
}