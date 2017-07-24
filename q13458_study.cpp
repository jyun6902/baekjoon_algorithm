#include <iostream>
#include <cstring>
using namespace std;
int N = 0;		// 시험장의 개수
int A[1000001];	// i번 시험장에 있는 응시자의 수
int B, C = 0;	// B=총감독관이 한 방에 감시할 수 있는 응시자 수 , C =부감독관
int dp[1000001];

int cal_num(int x)
{
	if (0 > x || x > 1000001)
		return 0;

	if (dp[x] != 0)
		return dp[x];

	int result = 0;

	dp[x] = 1;
	int y = x;
	y -= B;

	while (y > 0)
	{
		y -= C;
		++result;
	}
	return dp[x] += result;
}

int main()
{
	long long sum = 0;
	memset(A, 0, sizeof(A));
	memset(dp, 0, sizeof(dp));
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	cin >> B >> C;

	for (int i = 1; i <= N; i++)
		sum += cal_num(A[i]);

	cout << sum << endl;
	return 0;
}
