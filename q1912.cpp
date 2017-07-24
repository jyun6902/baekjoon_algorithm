#include <iostream>
using namespace std;
int  arr[100001];
int d[100001];
int max(int a, int b)
{
	if ( a >b )
		return a;
	else 
		return  b;
}

int main()
{
	int n= 0,max_d=-1000;
	cin >>n;

	for (int i = 1; i <= n ; i++)
	{
		cin>>arr[i];
	}

	d[1] =arr[1];

	for ( int i = 1 ; i <= n ; i++)
	{
		d[i] = max(d[i-1]+arr[i], arr[i]);
	}

	for (int i =1 ; i <= n ; i++ )
	{
		if ( max_d < d[i] )
			max_d = d[i];
	}

	cout <<max_d <<"\n";
	
	return 0;
}