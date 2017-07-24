#include <iostream>
using namespace std;
long long d[91];

int main()
{
	int N = 0 ;
	cin >> N;
	d[1]=1;
	d[2]=1;
	for (int i=3; i<=N; i++) {
        d[i] = d[i-1] + d[i-2];
    }
    cout << d[N] << '\n';
	return 0;
}