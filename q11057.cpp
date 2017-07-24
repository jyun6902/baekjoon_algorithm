#include <iostream>
using namespace std;
int d[1000][10];
int main()
{
	int N=0;
	int i = 0, j = 0;
	int result = 0;
	cin>> N;
	
	for (j = 0 ; j <= 9 ; j ++)
	{
		d[1][j] =1;
	}
	
	for ( i = 1; i <= N ; i++)
	{
		for ( j = 0 ; j <= 9 ; j ++ )
		{
			for (int k = 0 ; k <= j ; k ++ ) 
			{
				d[i][j] += d[i-1][k];
			}
			d[i][j]%=10007;
		}
	}

	for ( i = 0 ; i <= 9 ; i ++)
	result+=d[N][i];
	cout <<  result%10007;
	return 0;
}