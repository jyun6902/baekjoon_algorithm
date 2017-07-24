#include <iostream>
using namespace std;
int n;
int map[500][500];
int dp[500][500];		//생존일수

int max_result(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int go(int x, int y)
{

	if (dp[x][y] != -1)	//방문 했을 경우
		return dp[x][y];

	dp[x][y] = 1;

	if (y != n - 1 && map[x][y] < map[x][y + 1])	//동
	{
		dp[x][y] = max_result(dp[x][y],go(x, y + 1) + 1);
	}

	if (y != 0 && map[x][y] < map[x][y - 1])		//서
	{
		dp[x][y] = max_result(dp[x][y], go(x, y - 1) + 1);
	}

	if (x != n - 1 && map[x][y] < map[x + 1][y])	//남
	{
		dp[x][y] = max_result(dp[x][y], go(x + 1, y) + 1);
	}

	if (x != 0 && map[x][y] < map[x - 1][y])		//북
	{
		dp[x][y] = max_result(dp[x][y], go(x - 1, y) + 1);
	}

	return dp[x][y];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result = max_result(result, go(i, j));
		}
	}

	cout << result << endl;
	return 0;
}