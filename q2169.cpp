#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int land[1002][1002]; 
int dp[3][1002][1002];

int cal_max2 (int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

int cal_max3(int a, int b,int c)
{
	if ( cal_max2(a, b) < c)
		return c;
	else
		return cal_max2(a, b);
}
int main()
{
	cin >> N >> M;
	memset(land, 0, sizeof(land));
	memset(dp, 0, sizeof(dp));


	for (int i = 1 ; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> land[i][j];
			if (i == 1)
			{
				dp[0][i][j] = dp[0][i][j - 1] + land[i][j];
				dp[1][i][j] = dp[1][i][j - 1] + land[i][j];
				dp[2][i][j] = dp[2][i][j - 1] + land[i][j];
			}
		}
	}

	for (int i =2 ; i <= N ; i ++)
	{
		for (int j = 1; j <= M; j++)	//À§->¾Æ·¡
		{
			dp[2][i][j] = cal_max3(dp[2][i - 1][j], dp[1][i - 1][j], dp[0][i - 1][j]) + land[i][j];
		}
		dp[0][i][1] = dp[2][i][1];

		for (int j = 2; j <= M; j++)	//¿Þ->¿À
		{
				dp[0][i][j] = cal_max2(dp[0][i][j - 1], cal_max3(dp[2][i - 1][j], dp[1][i - 1][j], dp[0][i - 1][j])) + land[i][j];
		}

		dp[1][i][M] =dp[2][i][M];

		for (int j = M-1; j >= 1; j--)		//¿À->¿Þ
		{
				dp[1][i][j] = cal_max2(dp[1][i][j + 1], cal_max3(dp[2][i - 1][j], dp[1][i - 1][j], dp[0][i - 1][j])) + land[i][j];
		}

	}

	cout << cal_max3(dp[0][N][M], dp[1][N][M], dp[2][N][M]) << endl;
	return 0;
}