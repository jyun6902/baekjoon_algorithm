#include <iostream>
using namespace std;
int arr[1001]={0,};
int d[10001]={0,};

int max ( int a, int b)
{
	if ( a>b )
		return a;
	else 
		return b;
}
int main()
{
	int T=0;
	cin >>T;
	int i=0,j=0;

	for ( i = 1 ; i<= T; i++ )
	{
		cin >> arr[i];
	}

	for (i = 1 ; i <= T ; i ++ )
	{
		for ( j= 1 ; j <= i ; j ++ )
		{
			d[i] = max(d[i],d[i-j]+arr[j]);
		}
	}
	cout <<d[T];
	return 0;
}