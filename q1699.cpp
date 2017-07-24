#include <iostream>
using namespace std;
long long root[318] = { 0, };
long long dp[100001] = { 0, };
int main()
{
	int N = 1;
	cin >> N;

	for ( int i = 1 ; i <=317; i++)
	{
		root[i] = i*i;
	}
	
	for (int i = 0; i <= N; i++)
		dp[i] = -1;

	dp[0] = 0;
	
	for (int i = 1; i <= 317; i++)
	{
		for (int j= 0 ; j<= N ; j++)
		{
			if (j - root[i] >= 0 && dp[j - root[i]] != -1)
			{
				if (dp[j] == -1 || dp[j] > dp[j - root[i]] + 1)
					dp[j] = dp[j - root[i]] + 1;
			}
		}
	}
	cout << dp[N]<< endl;
	return 0;
}