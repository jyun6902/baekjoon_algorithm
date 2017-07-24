#include <iostream>
using namespace std;
int arr[1001];
int d[1001];
int main()
{
	int N=0, max=1;
	cin >>N;
	for ( int i=N; i >= 1 ; i-- )
	{
		cin >>arr[i];
	}

	for (int i = 1 ; i<= N ; i++)
	{
		d[i] = 1;
		for (int j = 1 ; j <= i ; j++)
		{
			//cout << " d[ "<< i<< " ] = "<<d[i] <<"||d[ "<<j<<" ] = " <<d[j]<<endl;
			if ( arr[j] < arr[i] && d[i] <d[j]+1)
				d[i] = d[j]+1;
		}
	}

	for (int i = 1; i <= N ; i++)
	{
		if (max < d[i] )
			max = d[i];
	}

	cout << max<<"\n";
	return 0;
}