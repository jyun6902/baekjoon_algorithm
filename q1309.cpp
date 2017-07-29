#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int N = 0; //우리의 크기
	long long dp[100001];
	memset(dp, 0, sizeof(dp));
	cin >> N;
	dp[1] = 3;	
	dp[2] = 7;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 2] + (2 * dp[i - 1]);
		dp[i] %= 9901;
	}
		cout << dp[N]<<endl;
	return 0;
}