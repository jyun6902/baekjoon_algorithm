#include <iostream>
#include <cstring>
using namespace std;
int house[1002][4];
int dp[3][4];	//»¡°­, ÃÊ·Ï, ÆÄ¶û
int min_2(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}
int main()
{
	int N = 0; 
	memset(dp, 0, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> house[i][j];
	}

	for (int i = 1; i <= N; i++)
	{
		dp[i%2][0] = min_2(dp[(i-1)%2][1], dp[(i - 1) % 2][2]) + house[i][0];
		dp[i%2][1] = min_2(dp[(i - 1) % 2][0], dp[(i - 1) % 2][2]) + house[i][1];
		dp[i%2][2] = min_2(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]) + house[i][2];
	}

	if ( N%2 == 1)
	cout << min_2(dp[1][0], min_2(dp[1][1], dp[1][2]))<<endl;
	
	else
	cout << min_2(dp[0][0], min_2(dp[0][1], dp[0][2])) << endl;
	return 0;

}