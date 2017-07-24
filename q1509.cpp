#include <cstdio>
using namespace std;
char input[2501] ;
int dp[2501][2501];
int min_dp[2501];

int pel(int s, int e)
{

	if ( s > e)
		return 1;

	if (dp[s][e] != -1)
	{
		return dp[s][e];
	}
	if (s == e)
	{
		return dp[s][e] = 1;
	}
	if (input[s] != input[e])
	{
		return dp[s][e] = 0;
	}
	else
	{
		s++;
		e--;
		return dp[s][e] = pel(s, e);
	}
}

int main()
{
	int count = 1;

	scanf("%s", input + 1);
	while (input[count] != '\0')	//input 문자열 개수
		count++;
	
	count -= 1;
	for (int i = 0; i <= 2500; i++)
	{
		for (int j = 0; j <= 2500; j++)
		{
			dp[i][j] = -1;
			if (i == j)
				dp[i][j] = 1;
		}
	}


	for (int i = 1; i <= count; i++)
	{
		for (int j = 1; j <= count; j++)
		{
			if (pel(j, i) == 1)
				dp[j][i] = 1;
			else 
				dp[j][i] = 0;
		}
	}

	min_dp[0] = 0;
	
	for (int i = 1; i <= count; i++)
	{
		min_dp[i] = -1;
		for (int j = 1; j <= i; j++)
		{
			if (dp[j][i] )
			{
				if (min_dp[i] == -1 || min_dp[i] > min_dp[j - 1] + 1)
					min_dp[i] = min_dp[j - 1] + 1;
			}
		}

	}
	printf("%d\n", min_dp[count]);

	return 0;
}