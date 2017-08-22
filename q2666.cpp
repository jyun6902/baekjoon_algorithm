#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n = 0, m = 0;	//n= 벽장 개수 m= 명령개수
int open[3] = { 0 };
int order[21] = { 0 };
int dp[21][21][21];	//현재열어야 하는 옷장, 현재열려있는 옷장open1,open2
int go(int door, int open_1, int open_2)
{
	if (door == m + 1)
		return 0;

	if (dp[door][open_1][open_2] != -1)
		return dp[door][open_1][open_2];

	return dp[door][open_1][open_2] = min(abs(open_1 - order[door]) + go(door + 1, order[door], open_2), abs(open_2 - order[door]) + go(door + 1, open_1, order[door]));
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> open[1] >> open[2] >> m;
	for (int i = 1; i <= m; i++)
		cin >> order[i];

	cout << go(1, open[1], open[2]) << endl;
	return 0;
}