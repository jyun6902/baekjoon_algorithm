#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int C = 0; 
	cin >> C;

	for (int t = 0; t < C; t++)
	{
		double N = 0,student = 0;
		double result = 0.0;
		cin >> N;
		int arr[1001];
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < N ; i++)
		{
			cin >> arr[i];
			result += arr[i];
		}

		result = result/N;

		for (int i = 0; i < N; i++)
		{
			if (arr[i] > result)
				student++;
		}

		result = (student/N)*100;
		cout << fixed;
		cout.precision(3);
		cout<<result<<"%"<< endl;
	}
	return 0;

}