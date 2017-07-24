#include <iostream>
using namespace std;
int grape[10001];
int d[10001][2];
int max(int a, int  b)
{
	if ( a > b)
		return a;
	else 
		return b;
}
int main()
{
	int n= 0;
	int i = 0;
	int result = 0;
	cin >> n;
	
	for (i = 1 ; i <= n ; i ++ )
	cin>>grape[i];

	d[1][0] = 0;
	d[1][1] = grape[1];
	d[1][2] = 0;
	for (i = 2 ; i <=n ; i++ )
	{
	d[i][0] = max(max(d[i-1][0],d[i-1][1]),d[i-1][2]);
	d[i][1] = d[i-1][0]+grape[i];
	d[i][2] = d[i-1][1]+grape[i];
	}

	result = max(max(d[n][0], d[n][1]), d[n][2]);
	cout <<result<<"\n";
	return 0;
}