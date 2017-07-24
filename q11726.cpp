#include <iostream>

using namespace std;
int d[1001]={0,};

int square(int N)
{
	if ( N==0)
	d[0]=1;
	if ( N==1)
	d[1]=1;

	if ( d[N] > 0 )
		return d[N];
	
	d[N] = square(N-1)+square(N-2);
	return d[N]%10007;
}

int main()
{
	int N =0;
	cin >> N;
	cout <<square(N);
	return 0;
}