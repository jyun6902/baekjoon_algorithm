#include <iostream>
using namespace std;
int d[100][10];
#define mod 1000000000;
int main()
{
	int N=0;
	int i=0, j =0;
	long long test=0;
	cin>>N;
	//d[i][j] = d[i-1][j-1]+d[i-1][j+1]
	for ( i = 1 ; i <= 9 ; i++)
		d[1][i] = 1;

	for ( i = 2 ; i <= N ; i ++ )
	{
		for ( j = 0 ; j <= 9 ; j++ )
		{
			d[i][j] = 0;
			if ( j-1 >= 0 )
			d[i][j] +=d[i-1][j-1];
			if( j+1 <=9 )
			d[i][j] +=d[i-1][j+1];

			d[i][j] %=mod;
		}
	}

	for ( i = 0 ; i <= 9 ; i ++)
			test+=d[N][i];
	cout <<test%mod;

	return 0 ;
}