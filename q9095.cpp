#include <iostream>
using namespace std;
//d[i]=d[i-1]+d[i-2]+d[i-3]
int arr[12] = {0,};
int d[12]={0,};
int cal(int N)
{
		d[1]=1;
		d[2]=2;
		d[3] =4;
	if ( d[N] > 0)
		return d[N];
	d[N] = cal(N-1)+cal(N-2)+cal(N-3);
	return d[N];
}

int main()
{
	int N = 0,T=0;
	cin >> T;

	for ( int i = 0 ; i < T; i ++ )
	{
		cin >>arr[i];
	}

	for ( int i = 0 ; i < T; i ++ )
	{
		cout <<cal(arr[i])<<endl;
	}
	return 0;
}