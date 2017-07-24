#include <iostream>
using namespace std;
int N;
int B, C = 0; //B=총감독관 C=부감독관
int result;
int num[1000001];
int dp[1000001];
int cal(int num)
{
	int count=1; 

	if (dp[num] != 0)
		return dp[num];

	result = num - B;

	if (result <= 0)
	{
		return dp[num] = count;
	}

	else
	{
		while (result > 0)
		{
			result -= C;
			count++;
		}
		return dp[num] = count;
	}

}
int main()
{
	long long int sum=0;
	cin >> N;
	

	for (int i = 1; i <= N; i++)
			cin >>num[i] ;
	
	cin >> B >> C;

	for (int i = 1; i <= N; i++)
		sum+=cal(num[i]);
	
	cout << sum;
	return 0;
}