#include <iostream>
#include <cstring>
#include <string>
#include <deque>
using namespace std;

int N;
deque <pair<int, int>>  mirror;
int door1_x, door1_y, door2_x, door2_y;
string maps[52];
int dp[50][50];
int go(int x, int y)
{
	if (x < 0 || x >N || y < 0 || y> N)
		return 1;

	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;

	while (!mirror.empty())
	{
		int a = mirror.back().first;
		int b = mirror.back().second;

		if ( maps[x][y+1] == )
	}
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> maps[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (maps[i][j] == '#')
			{
				door1_x = i;
				door1_y = j;
				door2_x = i;
				door2_y = j;
			}

			else if (maps[i][j] == '!')
				mirror.push_back({ i,j });
		}
	}

	go(door2_x, door2_y);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << maps[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}