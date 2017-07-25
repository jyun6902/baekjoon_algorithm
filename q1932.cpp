#include <iostream>
#include <cstring>
#define MAX(x,y) (x>y? x:y)
using namespace std;
int n = 0; //»ï°¢ÇüÀÇ Å©±â
int triangle[505][505];
int dp[505][505];	//»ï°¢ÇüÅ©±â 1~500ÀÌÇÏ : 125250 = (500*501)/2

int main()
{
	cin >> n;
	memset(triangle, 0, sizeof(triangle));
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1 ; j <=i ; j++)
		cin >> triangle[i][j];
	}
	
	dp[1][1] = triangle[1][1];//1Ãþ
	/*
	dp[2][1] = triangle[2][1] + dp[1][1];	//2Ãþ
	dp[2][2] = triangle[2][2] + dp[1][1];

	dp[3][1] = triangle[3][1] + dp[2][1]; //3Ãþ
	dp[3][2] = triangle[3][2] + MAX(dp[2][1], dp[2][2]);
	dp[3][3] = triangle[3][3] + dp[2][2];
	
	dp[4][1] = triangle[4][1] + dp[3][1] ; //4Ãþ
	dp[4][2] = triangle[4][2] + MAX(dp[3][1], dp[3][2]);
	dp[4][3] = triangle[4][3] + MAX(dp[3][2], dp[3][3]);
	dp[4][4] = triangle[4][4] + dp[3][3] ;

	dp[5][1] = triangle[5][1] + dp[4][1] ; //5Ãþ
	dp[5][2] = triangle[5][2] + MAX(dp[4][1], dp[4][2]);
	dp[5][3] = triangle[5][3] + MAX(dp[4][2], dp[4][3]);
	dp[5][4] = triangle[5][4] + MAX(dp[4][3], dp[4][4]);
	dp[5][5] = triangle[5][5] + dp[4][4] ;
	*/

	for (int floor = 2; floor <= n ; floor++)
	{
		int a = 1;
		for (int j = 1; j <= floor; j++)
		{
			if ( j == 1 )			//Ãþ¿¡¼­ Ã¹ºÎºÐÀÏ °æ¿ì
			dp[floor][j] = triangle[floor][j]+dp[floor-1][1];

			else if ( j== floor)	//Ãþ¿¡¼­ ³¡ºÎºÐÀÏ °æ¿ì
			dp[floor][j] = triangle[floor][j] + dp[floor-1][floor-1];

			else
			{
				dp[floor][j] = triangle[floor][j] + MAX(dp[floor-1][a], dp[floor-1][a+1]);
				a++;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n ; i++)
	{
		if (ans < dp[n][i])
			ans = dp[n][i];
	}

	cout << ans << endl;
	return 0;
}