#include <iostream>
using namespace std;
int maze[1001][1001];
int number[1001][1001];

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int max(int a, int b, int c)
{
	if (max(a, b) > c)
		return max(a, b);
	else
		return c;
}
int main()
{
	int n = 0, m = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> maze[i][j];
		}
	}
	number[1][1] = maze[1][1];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
		/*	if (j == 1)
				number[i + 1][j] = number[i][j] + maze[i + 1][j];
			if (i == 1)
				number[i][j + 1] = number[i][j] + maze[i][j + 1];
*/
			//else
			number[i + 1][j + 1] = max(number[i][j + 1], number[i + 1][j], number[i][j]) + maze[i + 1][j + 1];
		}
	}
	//cout << "==================================" << endl;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << number[i][j] << " ";
		}
		cout << endl;
	}

	cout << number[n][m];
	return 0;
}