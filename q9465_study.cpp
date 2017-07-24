#include <iostream>
#include <cstring>
using namespace std;
long long sticker[100002][4];
long long dp[100002][4];

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

int main()
{
	int T = 0, n = 0;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		memset(sticker, 0, sizeof(sticker));
		memset(dp, 0, sizeof(dp));
		cin >> n;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
				cin >> sticker[j][i];
		}
		dp[0][0] = dp[0][1] = dp[0][2] = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[i][0] = max_3(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);	 //뜯지 않음
			dp[i][1] = max_2(dp[i - 1][2], dp[i - 1][0]) + sticker[i][0];//위쪽 스티커 뜯음
			dp[i][2] = max_2(dp[i - 1][1], dp[i - 1][0]) + sticker[i][1];//아래쪽 스티커 뜯음
		}
		long long result = 0;

		for (int i = 1; i <= n; i++)
			result = max_2(max_2(result, dp[i][0]), max_2(dp[i][1], dp[i][2]));

		cout << result << endl;
	}//for test_case

	return 0;
}