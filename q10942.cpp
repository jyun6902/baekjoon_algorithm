#include <cstdio>
using namespace std;
int input[2001];
int dp[2001][2001];

int pel(int s, int e)
{
	if (e< s)
		return 1;

	if (dp[s][e] != -1)
		return dp[s][e];

	if (s == e)
		return dp[s][e] = 1;

	if (input[s] != input[e])
		return dp[s][e] = 0;

	else
	{
		s++;
		e--;
		return dp[s][e] = pel(s, e);
	}
}

int main()
{
	int n = 0, m = 0, s = 0, e = 0;
	scanf("%d", &n);

	for (int i = 0; i <= 2000; i++)			//dp 초기화 
	{
		for (int j = 0; j <= 2000; j++)
			dp[i][j] = -1;
	}

	for (int i = 1; i <= n; i++)
		scanf("%d", &input[i]);

	scanf("%d", &m);					//m = 질문갯수

	for (int j = 1; j <= m; j++)		//질문들
	{
		scanf("%d %d", &s, &e);
		printf("%d \n", pel(s, e));
	}
	return 0;
}