#include <iostream>
#include <cstring>
using namespace std;		//TOP_DOWN
int map[500][500];
int dp[500][500];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int m,n;
int go(int x, int  y)
{
	if (x == n - 1 && y == m - 1)
		return 1;

	if (dp[x][y] != -1)//방문 했을 경우
		return dp[x][y];

	dp[x][y] = 0;

	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx && nx < n && 0 <= ny && ny < m)
		{
			if (map[x][y] > map[nx][ny])
				dp[x][y] += go(nx, ny);
		}
	}
	return dp[x][y];
	
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;	//m= 세로 n = 가로
	
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < m ; j++)
		{
			cin >> map[i][j];
		}
	}
	cout << go(0, 0) <<endl;
	return 0;
}
