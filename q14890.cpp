#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N = 0, L = 0;
int maps[210][210] = {};
bool visit[210][210] = {};
int sum = 0;

void cal_garo(int x, int y)
{
	int k = 0;

	for (k = 1; k <= N; k++)
	{
		if (abs(maps[x][k] - maps[x][k + 1]) > 1)
			break;

		else if (maps[x][k] - maps[x][k + 1] == 0)
			continue;

		else if (maps[x][k] - maps[x][k + 1] == -1) //증가
		{
			int flag = 0;
			for (int p = 0; p < L; p++)
			{
				if (k - p < 1 || visit[x][k - p] == 1 || maps[x][k - p] != maps[x][k])
				{
					flag = 1;
					break;
				}

				visit[x][k - p] = 1;

			}// for p
			if (flag == 1)
				break;
		}

		else //if (maps[x][k] - maps[x][k + 1] == 1)// 증가
		{
			int flag = 0;
			for (int p = 0; p < L; p++)
			{
				if (k + p + 1 > N || visit[x][k + p + 1] == 1 || maps[x][k] - 1 != maps[x][k + p + 1])
				{
					flag = 1;
					break;
				}

				visit[x][k + p + 1] = 1;

			}// for p
			if (flag == 1)
				break;
			k += (L - 1);
		}
	}

	if (k >= N)
		sum++;
}

void cal_sero(int x, int y)
{
	int k = 0;

	for (k = 1; k <= N; k++)
	{
		if (abs(maps[k][y] - maps[k + 1][y]) > 1)
			break;

		else if (maps[k][y] - maps[k + 1][y] == 0)
			continue;

		else if (maps[k][y] - maps[k + 1][y] == -1) //증가
		{
			int flag = 0;
			for (int p = 0; p < L; p++)
			{
				if (k - p < 1 || visit[k - p][y] == 1 || maps[k - p][y] != maps[k][y])
				{
					flag = 1;
					break;
				}

				visit[k - p][y] = 1;

			}// for p
			if (flag == 1)
				break;
		}

		else //if (maps[x][k] - maps[x][k + 1] == 1)// 증가
		{
			int flag = 0;
			for (int p = 0; p < L; p++)
			{
				if (k + p + 1 > N || visit[k + p + 1][y] == 1 || maps[k][y] - 1 != maps[k + p + 1][y])
				{
					flag = 1;
					break;
				}

				visit[k + p + 1][y] = 1;

			}// for p
			if (flag == 1)
				break;
			k += (L - 1);
		}
	}

	if (k >= N)
		sum++;
}


int main()
{
	cin >> N >> L;
	memset(maps, -1, sizeof(maps));
	memset(visit, 0, sizeof(visit));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> maps[i][j];
	}

	for (int i = 1; i <= N; i++)
		cal_garo(i, 1);

	memset(visit, 0, sizeof(visit));

	for (int i = 1; i <= N; i++)
		cal_sero(1, i);

	cout << sum << endl;
	return 0;
}