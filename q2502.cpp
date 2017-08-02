#include <iostream>
using namespace std;
int dp_a[100001];
int dp_b[100001];
int dp[100001];

int main()
{
	int A = 1, B = 1;	//A= 처음 만난 날 준 떡 갯수 B= 그 다음 날 준 떡의 갯수
	int D, K = 0;	//D= 할머니가 넘어온 날 K=그 날 호랑이에게 준 떡의 갯수
	cin >> D >> K;
	dp_a[1] = 1;
	dp_a[2] = 0;
	dp_a[3] = 1;

	dp_b[1] = 0;
	dp_b[2] = 1;
	dp_b[3] = 1;
	for (int i = 4; i <= D; i++)
	{
		dp_a[i] = dp_a[i - 1] + dp_a[i - 2];
		dp_b[i] = dp_b[i - 1] + dp_b[i - 2];
	}

	while (1)
	{
		A++;
		int temp = K - (dp_a[D] * A);
		if (temp % (dp_b[D] * B) == 0)
		{
			B = temp / dp_b[D];
			break;
		}
	}

	cout << A << endl;
	cout << B << endl;
	return 0;
}