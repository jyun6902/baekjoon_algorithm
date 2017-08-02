#include <iostream>
#include <cstring>
using namespace std;
int maps[100001][4];
int max_dp[3][4];
int min_dp[3][4];
int max_2(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int max_3(int a, int b, int c)
{
	if (max_2(a, b) > c)
		return max_2(a, b);
	else
		return c;
}
int min_2(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int min_3(int a, int b, int c)
{
	if (min_2(a, b) < c)
		return min_2(a, b);
	else
		return c;
}

int main()
{
	int N = 0;
	int i, j = 0;
	cin >> N;
	memset(maps, 0, sizeof(maps));
	memset(max_dp, 0, sizeof(max_dp));
	memset(min_dp, 0, sizeof(min_dp));
	int min_result = 10, max_result = 0;
	int  max_y = 0, min_y = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> maps[i][j];
			if (i == 0)
			{
				max_dp[0][j] = maps[0][j];
				min_dp[0][j] = maps[0][j];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		max_dp[i % 2][0] = max_2(max_dp[(i - 1) % 2][0], max_dp[(i - 1) % 2][1]) + maps[i][0];
		max_dp[i % 2][1] = max_3(max_dp[(i - 1) % 2][0], max_dp[(i - 1) % 2][1], max_dp[(i - 1) % 2][2]) + maps[i][1];
		max_dp[i % 2][2] = max_2(max_dp[(i - 1) % 2][1], max_dp[(i - 1) % 2][2]) + maps[i][2];

		min_dp[i % 2][0] = min_2(min_dp[(i - 1) % 2][0], min_dp[(i - 1) % 2][1])+ maps[i][0];
		min_dp[i % 2][1] = min_3(min_dp[(i - 1) % 2][0], min_dp[(i - 1) % 2][1], min_dp[(i - 1) % 2][2]) + maps[i][1];
		min_dp[i % 2][2] = min_2(min_dp[(i - 1) % 2][1], min_dp[(i - 1) % 2][2]) + maps[i][2];

	}
	if (N % 2 == 1)
		cout << max_3(max_dp[1][0], max_dp[1][1], max_dp[1][2]) << " " << min_3(min_dp[1][0], min_dp[1][1], min_dp[1][2]) << endl;

	else
		cout << max_3(max_dp[0][0], max_dp[0][1], max_dp[0][2]) << " " << min_3(min_dp[0][0], min_dp[0][1], min_dp[0][2]) << endl;
	return 0;
}