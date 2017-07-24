#include <iostream>
using namespace std;
int d[1001]={0,};
int square(int N)
{
	d[0]=1;
	d[1]=1;
	if ( d[N] > 0)
		return d[N]%10007;
	d[N]=2*square(N-2)+square(N-1);
	return d[N]%10007;
}

int main()
{
	int N =0;
	cin >> N;
	cout <<square(N)<<endl;
	return 0;
}
