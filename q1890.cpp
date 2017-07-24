#include <iostream>
using namespace std;
int number[501][501];
long long int dp[501][501];
int main()
{
	int n = 0, value =0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> number[i][j];
		}
	}
	
	dp[1][1]=1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] != 0)
			{
				value = number[i][j];

				if (i != n || j != n)
				{
					dp[i][j + value] += dp[i][j];
					dp[i + value][j] += dp[i][j];
				}
			}

		}
	}

	cout << "===================" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << dp[i][j] << " ";

		}
		cout << endl;
	}

	cout << dp[n][n] << endl;
		
return 0;
}