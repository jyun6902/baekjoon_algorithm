//LIS »ç¿ë (Longest Increasing Subsequence)
#include <iostream>
using namespace std;

int main()
{
	int N = 0;	//Àü±êÁÙÀÇ °¹¼ö
	int line[501] = { 0 }, d[501] = { 0 };
	int max_a = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (max_a < a)
			max_a = a;
		line[a] = b;
	}

	for (int i = 1; i <= max_a; i++)
	{
		d[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (line[j] < line[i] && d[i] < d[j] + 1 && line[j] != 0)
				d[i] = d[j] + 1;
		}
	}

	int answer = 0;
	for (int i = 1; i <= max_a; i++)
	{
		if (answer < d[i])
			answer = d[i];
	}
	cout << N - answer << endl;
	return 0;
}