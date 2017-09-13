#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;
int maps[1002][1002] = {};
bool visit[2][1002][1002] = {};//cnt = 0,1 일때 구분
/*BFS while{for()} 까먹지말자*/
int main()
{
	int N, M = 0;//1<=N<=1000 1<=M<=1000
	deque <pair<pair<int, int>, int>>dq;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	int result = 1, n_x = 0, n_y = 0;//result=1->시작하는 칸도 포함
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			scanf("%1d", &maps[i][j]);
	}
	dq.push_back({ {1,1}, 0 });
	visit[0][1][1] = 1;
	while (!dq.empty())
	{
		int dq_s = dq.size();
		for (int dq_t = 0; dq_t < dq_s; dq_t++)
		{
			int x = dq.front().first.first;
			int y = dq.front().first.second;
			int cnt = dq.front().second;
			dq.pop_front();
			if (x == N && y == M)
			{
				cout << result << endl;
				return 0;
			}
			for (int i = 0; i < 4; i++)
			{
				n_x = x + dx[i];
				n_y = y + dy[i];

				if (n_x < 1 || n_x >N || n_y <1 || n_y> M || visit[cnt][n_x][n_y] == 1 || cnt > 1)
					continue;

				if (maps[n_x][n_y] == 1)
				{
					if (cnt < 1)
					{
						int temp = cnt + 1;
						dq.push_back({ {n_x, n_y}, temp });
						visit[temp][n_x][n_y] = 1;
					}
				}

				else if (maps[n_x][n_y] == 0)
				{
					dq.push_back({ { n_x, n_y }, cnt });
					visit[cnt][n_x][n_y] = 1;
				}
			}
		}//for
		result++;
	}

	cout << "-1" << endl;
	return 0;
}