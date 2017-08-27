#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int dp[1002][1002];
int N = 0, s[1002] = { 0 };

int main()
{
	memset(dp, 0, sizeof(dp));

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> s[i];

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (i + k > N || i + j >= i + k)
					continue;
				
				if (abs(s[i] - s[i + k]) > dp[i][i + k])
					dp[i][i + k] = abs(s[i] - s[i + k]);

				if (dp[i][i + k] < dp[i][i + j] + dp[i + j + 1][i + k])
					dp[i][i + k] = dp[i][i + j] + dp[i + j + 1][i + k];
			}
		}
	}
	cout << dp[1][N] << endl;
	return 0;
}