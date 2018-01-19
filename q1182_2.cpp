#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, S = 0, cnt = 0, n = 0;
	vector <int> arr;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		arr.push_back(n);
	}

	for (int i = 0; i < (1 << N); i++)
	{
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
				sum += arr[j];
		}

		if (sum == S)
			cnt++;
	}

	if (S == 0)
		cnt--; //empty set
	cout << cnt << endl;
	return 0;
}