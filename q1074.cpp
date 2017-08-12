#include <iostream>
#include <cmath>
using namespace std;

long long cal(int N, int r, int c)
{
	if (N == 0)
		return 0;

	if (r < pow(2, N - 1) && c < pow(2, N - 1))
		return cal(N - 1, r, c);

	else if (r < pow(2, N - 1) && c >= pow(2, N - 1))
		return pow(4, N - 1)+ cal(N-1, r, c-pow(2,N-1));

	else if (r >= pow(2, N - 1) && c < pow(2, N - 1))
		return (pow(4, N - 1) * 2) + cal(N-1, r-pow(2, N-1), c) ;

	else if (r >= pow(2, N - 1) && c >= pow(2, N - 1))
		return (pow(4, N - 1) * 3) + cal(N-1, r-pow(2,N-1), c-pow(2,N-1));
}
int main()
{
	int N = 0, r = 0, c = 0;
	cin >> N >> r >> c;

	cout<< cal(N, r, c)<<endl;
	return 0;
}