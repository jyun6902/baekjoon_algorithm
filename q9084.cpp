#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T = 0, N=0, M=0;//test case
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;//동전 가지수 (1<=N<=20)
		int coin[21] = {}, dp[10001] = {};

		for (int coin_case = 1; coin_case <= N; coin_case++)
			cin >> coin[coin_case];
		cin >> M;//동전으로 만들어야 할 금액

		dp[0] = 1;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j <= M; j++)
			{
				if (j - coin[i] >= 0)
					dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[M] << endl;
	}

	return 0;
}