#include <iostream>
#include <deque>
#include <cstdio>

using namespace std;

int N = 0;
int max_result = 0;
void cal(int cnt, int dir, int maps[22][22])
{
	int maps_copy[22][22] = {};

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			maps_copy[i][j] = maps[i][j];
	}

	if (cnt >= 6)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (max_result < maps_copy[i][j])
					max_result = maps_copy[i][j];
			}
		}
		return;
	}

	if (dir == 1)//µ¿
	{
		for (int i = 0; i < N; i++)
		{
			deque <int > dq;
			for (int j = 0; j < N; j++)
			{
				if (maps_copy[i][j] != 0)
				{
					dq.push_back(maps_copy[i][j]);
					maps_copy[i][j] = 0;
				}
			}
			int k = N - 1;
			while (!dq.empty())
			{
				int num = dq.back();
				dq.pop_back();
				maps_copy[i][k] = num;
				k--;
			}

			for (int j = N - 1; j > 0; j--)
			{
				if (maps_copy[i][j] == maps_copy[i][j - 1])
				{
					maps_copy[i][j] += maps_copy[i][j - 1];
					maps_copy[i][j - 1] = 0;
					j--;
				}
			}
			////////////////////////////////////////////
			for (int j = 0; j < N; j++)
			{
				if (maps_copy[i][j] != 0)
				{
					dq.push_back(maps_copy[i][j]);
					maps_copy[i][j] = 0;
				}
			}
			k = N - 1;
			while (!dq.empty())
			{
				int num = dq.back();
				dq.pop_back();
				maps_copy[i][k] = num;
				k--;
			}
		}
	}

	else if (dir == 2)//¼­
	{
		for (int i = 0; i < N; i++)
		{
			deque <int > dq;
			for (int j = 0; j < N; j++)
			{
				if (maps_copy[i][j] != 0)
				{
					dq.push_back(maps_copy[i][j]);
					maps_copy[i][j] = 0;
				}
			}
			int k = 0;
			while (!dq.empty())
			{
				int num = dq.front();
				dq.pop_front();
				maps_copy[i][k] = num;
				k++;
			}

			for (int j = 0; j < N - 1; j++)
			{
				if (maps_copy[i][j] == maps_copy[i][j + 1])
				{
					maps_copy[i][j] += maps_copy[i][j + 1];
					maps_copy[i][j + 1] = 0;
					j++;
				}
			}
			////////////////////////////////////////////
			for (int j = 0; j < N; j++)
			{
				if (maps_copy[i][j] != 0)
				{
					dq.push_back(maps_copy[i][j]);
					maps_copy[i][j] = 0;
				}
			}
			k = 0;
			while (!dq.empty())
			{
				int num = dq.front();
				dq.pop_front();
				maps_copy[i][k] = num;
				k++;
			}
		}
	}

	else if (dir == 3)//³²
	{
		for (int i = 0; i < N; i++)
		{
			deque <int > dq;
			for (int j = 0; j < N; j++)
			{
				if (maps_copy[j][i] != 0)
				{
					dq.push_back(maps_copy[j][i]);
					maps_copy[j][i] = 0;
				}
			}
			int k = N - 1;
			while (!dq.empty())
			{
				int num = dq.back();
				dq.pop_back();
				maps_copy[k][i] = num;
				k--;
			}

			for (int j = N - 1; j > 0; j--)
			{
				if (maps_copy[j][i] == maps_copy[j - 1][i])
				{
					maps_copy[j][i] += maps_copy[j - 1][i];
					maps_copy[j - 1][i] = 0;
					j--;
				}
			}
			////////////////////////////////////////////
			for (int j = 0; j < N; j++)
			{
				if (maps_copy[j][i] != 0)
				{
					dq.push_back(maps_copy[j][i]);
					maps_copy[j][i] = 0;
				}
			}
			k = N - 1;
			while (!dq.empty())
			{
				int num = dq.back();
				dq.pop_back();
				maps_copy[k][i] = num;
				k--;
			}
		}
	}

	else if (dir == 4)//ºÏ
	{
		for (int i = 0; i < N; i++)
		{
			deque <int > dq;
			for (int j = 0; j < N; j++)
			{
				if (maps_copy[j][i] != 0)
				{
					dq.push_back(maps_copy[j][i]);
					maps_copy[j][i] = 0;
				}
			}
			int k = 0;
			while (!dq.empty())
			{
				int num = dq.front();
				dq.pop_front();
				maps_copy[k][i] = num;
				k++;
			}

			for (int j = 0; j < N - 1; j++)
			{
				if (maps_copy[j][i] == maps_copy[j + 1][i])
				{
					maps_copy[j][i] += maps_copy[j + 1][i];
					maps_copy[j + 1][i] = 0;
					j++;
				}
			}
			////////////////////////////////////////////
			for (int j = 0; j < N; j++)
			{
				if (maps_copy[j][i] != 0)
				{
					dq.push_back(maps_copy[j][i]);
					maps_copy[j][i] = 0;
				}
			}
			k = 0;
			while (!dq.empty())
			{
				int num = dq.front();
				dq.pop_front();
				maps_copy[k][i] = num;
				k++;
			}
		}
	}

	cal(cnt + 1, 1, maps_copy);
	cal(cnt + 1, 2, maps_copy);
	cal(cnt + 1, 3, maps_copy);
	cal(cnt + 1, 4, maps_copy);
}

int main()
{
	int maps[22][22] = {};
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%d", &maps[i][j]);
	}
	cal(0, 0, maps);

	printf("%d\n", max_result);
	return 0;
}