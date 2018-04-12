#include <iostream>
#include <cstdio>
#include <deque>
#include <cstring>
using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int main()
{
	int T = 0;
	scanf("%d", &T);;

	for (int t_c = 1; t_c <= T; t_c++)
	{
		int result = 0;
		int M, N, K = 0; // M=가로 N=세로
		int maps[52][52] = {};
		int visit[52][52] = {};
		memset(maps, 0, sizeof(maps));
		memset(visit, 0, sizeof(visit));
		scanf("%d %d %d", &M, &N, &K);

		for (int i = 0; i < K; i++)
		{
			int x, y = 0;
			scanf("%d %d", &y, &x);
			maps[x][y] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (maps[i][j] == 1 && visit[i][j] == 0)
				{
					visit[i][j] = 1;
					result++;
					deque <pair <int, int >> dq;
					dq.push_back({ i,j });

					while (!dq.empty())
					{
						int x = dq.front().first;
						int y = dq.front().second;
						dq.pop_front();

						for (int k = 0; k < 4; k++)
						{
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny] || maps[nx][ny] == 0)
								continue;

							visit[nx][ny] = 1;
							dq.push_back({ nx, ny });
						}
					}

				}
			}
		}
		printf("%d\n", result);
	}

	return 0;
}