#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int room[52][52];
int dp[52][52];
int N;

int cal_min2(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int cal_min3(int a, int b,int c)
{
	if (cal_min2(a,b) < c)
		return cal_min2(a, b);
	else
		return c;
}

int cal_min4(int a, int b, int c,int d)
{
	return cal_min2(cal_min2(a, b), cal_min2(c, d));
}

int main()
{
	int i, j = 0;
	cin >> N;
	memset(room, -1, sizeof(room));
	memset(dp, 10, sizeof(dp));
	
	dp[1][1] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &room[i][j]);
		}
	}

	
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (room[i][j] == 0 )
				{
					if ( dp[i][j] > cal_min4(dp[i][j - 1], dp[i - 1][j], dp[i][j + 1], dp[i + 1][j]) +1)
					dp[i][j] = cal_min4(dp[i][j - 1], dp[i - 1][j], dp[i][j + 1], dp[i + 1][j]) + 1;
				}

				else
				{
					if (dp[i][j] > cal_min4(dp[i][j - 1], dp[i - 1][j], dp[i][j + 1], dp[i + 1][j]) )
					dp[i][j] = cal_min4(dp[i][j - 1], dp[i - 1][j], dp[i][j + 1], dp[i + 1][j]);
				}
			}
		}
	}
	
	cout << dp[N][N];

	return 0;
}