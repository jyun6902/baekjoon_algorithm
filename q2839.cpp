#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int min_result = 987654321;
int N = 0;
int dp[5001] = {};
int main()
{
	scanf("%d", &N);
	memset(dp, 1, sizeof(dp));

	for (int i = 1; i < 1666; i++)
		dp[3 * i] = i;
	
	for (int i = 1; i <= 1000; i++)
		dp[5 * i] = i;

	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			if (3 * i + 5 * j > 5000)
				break;

			if (dp[3 * i + 5 * j] > i + j)
				dp[3 * i + 5 * j] = i + j;
		}
	}

	if (dp[N] > 10000)
		dp[N] = -1;
	printf("%d\n", dp[N]);
	return 0;
}