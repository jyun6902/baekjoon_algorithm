#include <iostream>
using namespace std;

int main()
{
	int n = 0, T = 0, cnt = 0;
	int arr[51] = {};
	cin >> n >> T;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
		if (arr[i] > T)
		{
			cout << cnt << endl;
			return 0;
		}

		else if (arr[i] < T &&  i == n)
		{
			cout << cnt + 1 << endl;
			return 0;
		}
		cnt++;
	}
}