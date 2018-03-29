#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int dp[41] = {};
vector <pair<int, int>> v[41];//0, 1 °¹¼ö
int cal(int n)
{
	if (n <= 1)
	{
		if (n == 0)
			v[0].push_back({ 1, 0 });

		else
			v[1].push_back({ 0, 1 });
		
		return n;
	}
	else
	{
		if (dp[n] > 0)
			return dp[n];

		dp[n] = cal(n - 1) + cal(n - 2);
		v[n].push_back({ v[n - 1].front().first+ v[n-2].front().first, v[n-1].front().second +v[n-2].front().second});
		return dp[n];
	}
}
int main()
{
	int T = 0, N=0;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cal(N);
		cout << v[N].front().first << " " << v[N].front().second << endl ;
	}
	
	return 0;
}