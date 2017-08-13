#include <iostream>
using namespace std;

int main()
{
	int N = 0, max_result = 0;
	int arr[1001], arr_reverse[1001];
	int dp1[1001], dp2[1001], sum[1001];
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		arr_reverse[N - 1 - i] = arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		dp1[i] = 1;
		dp2[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp1[i] < dp1[j] + 1)		//가장 증가
				dp1[i] = dp1[j] + 1;

			if (arr_reverse[j] <arr_reverse[i] && dp2[i] < dp2[j] + 1)	//가장 감소
				dp2[i] = dp2[j] + 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (max_result < dp1[i] + dp2[N - 1 - i])
			max_result = dp1[i] + dp2[N - 1 - i];
	}
	cout << max_result - 1 << endl;
	return 0;
}