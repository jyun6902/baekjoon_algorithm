#include <iostream>
using namespace std;
//Combination(조합)으로 풀기
long long  comb[31][31] = { 0 };
void cal_comb(int n)
{
	for (int i = 0; i <= n; i++)
	{
		comb[0][0] = 1;
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				comb[i][j] = 1;
			else
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
}
int main()
{
	int T = 0, N, M;	//테스트 개수 N=서 M =동 N <= M
	cin >> T;
	cal_comb(30);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> M;
		cout << comb[M][N] << endl;
	}

	return 0;
}