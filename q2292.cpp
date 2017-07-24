#include <iostream>
using namespace std;
int dp[100000];
int main()
{
	int N = 0;
	int result;
	cin >> N;

	for (int i = 1; i < 100000; i++)
	{
		dp[i] = 3 * i*i - 3 * i + 1;
	}
	dp[0] = 0;
	for (int i = 1; i < 100000; i++)
	{
		if (dp[i - 1] < N && dp[i] >= N)
		{
			result = i;
			i = 100000;
		}
	}
	cout << result;
	return 0;
}