#include <iostream>
#include <cstring>
using namespace std;
int arr[101][101];
int main()
{
	int N = 0;
	int result = 0;
	int x, y = 0;
	memset(arr, 0, sizeof(arr));
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		for (int a = x; a < x + 10; a++)
		{
			for (int b = y; b < y + 10; b++)
				arr[a][b] += 1;
		}
	}

	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (arr[i][j] >= 1)
				result++;
		}
	}

	cout << result << endl;
	return 0;
}