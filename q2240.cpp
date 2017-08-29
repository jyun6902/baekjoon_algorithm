#include <iostream>
#include <cstring>
using namespace std;
//크기 널널하게 잡기
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
	int T = 0, W = 0;	//T초동안 떨어짐(1<=T<=1000 //최대 W번 움직임 가능 (0<=W<=30)
	int tree[1010] = { 0 };
	int dp[3][1010][33];	//나무번호,sec,  turn
	int result = 0;
	cin >> T >> W;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= T; i++)
		cin >> tree[i];

	for (int sec = 1; sec <= T; sec++)
	{
		for (int move = 0; move <= W; move++)
		{
			if (tree[sec] == 1)
			{
				dp[1][sec][move] = max_3(dp[1][sec][move], dp[1][sec - 1][move] + 1, dp[2][sec - 1][move - 1] + 1);
				dp[2][sec][move] = max_3(dp[2][sec][move], dp[2][sec - 1][move], dp[1][sec - 1][move - 1]);
			}

			else// tree[sec] == 2
			{
				dp[1][sec][move] = max_3(dp[1][sec][move], dp[1][sec - 1][move], dp[2][sec - 1][move - 1]);
				dp[2][sec][move] = max_3(dp[2][sec][move], dp[2][sec - 1][move] + 1, dp[1][sec - 1][move - 1] + 1);
			}
		}
	}

	for (int move = 0; move <= W; move++)
		result = max_3(result, dp[1][T][move], dp[2][T][move]);

	cout << result << endl;

	return 0;
}