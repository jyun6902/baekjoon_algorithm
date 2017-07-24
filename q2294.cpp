#include <iostream>
using namespace std;

int d[10001] = { 0, };
int main()
{
	int n = 0, k = 0, result = 1000000;
	int coin[100] = { 0, };
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int i = 0; i <= k; i++)
		d[i] = -1;

	d[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j - coin[i] >= 0 && d[j - coin[i]] != -1)
			{
				if (d[j] == -1 || d[j] > d[j - coin[i]] + 1)
					d[j] = d[j - coin[i]] + 1;
			}
		}
	}
	cout << d[k] << endl;
	return 0;
}