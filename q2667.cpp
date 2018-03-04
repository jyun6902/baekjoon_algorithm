#include <iostream>
#include <deque>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1 ,0, 0 };
int main()
{
	int N = 0; // 5¡ÂN¡Â25
	int maps[26][26] = {};
	bool visit[26][26] = {};
	deque <pair <int, int > > dq;
	int flag = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &maps[i][j]);

			if (maps[i][j] == 1)
				maps[i][j] = -1;

		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (maps[i][j] == -1)
			{
				++cnt;
				dq.push_back({ i,j });
				while (!dq.empty())
				{
					int dq_size = dq.size();
					
					for (int k = 0; k < dq_size; k++)
					{
						int x = dq.front().first;
						int y = dq.front().second;
						dq.pop_front();
						visit[x][y] = 1;
						maps[x][y] = cnt;
						for (int p = 0; p < 4; p++)
						{
							int now_x = x + dx[p];
							int now_y = y + dy[p];

							if (now_x < 0 || now_x >= N || now_y < 0 || now_y >= N || visit[now_x][now_y] != 0)
								continue;

							if (maps[now_x][now_y] == -1)
								dq.push_back({ now_x, now_y });
						}

					}

				}//while
			}
		}
	}


	vector <int> v[625];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (maps[i][j] != 0)
				v[maps[i][j]].push_back(1);
		}
	}

	vector <int> result;
	for (int i = 1; i <= cnt; i++)
	{
		result.push_back(v[i].size());
	}

	sort(result.begin(), result.end());
	cout << cnt << endl;

	for (int i = 0; i < cnt; i++)
		cout << result[i] << endl;
	return 0;
}
