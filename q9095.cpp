#include <iostream>
using namespace std;

int go(int cnt, int sum, int goal)
{
	if (sum > 10 || sum > goal)
		return 0;

	if (goal == sum)
		return 1;
	int now = 0;
	for (int i = 1; i <= 3; i++)
	{
		now += go(cnt + 1, sum + i, goal);
	}
	return now;
}
int main()
{
	int T = 0;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int n = 0;
		cin >> n;
		cout << go(0, 0, n) << endl;
	}

	return 0;
}