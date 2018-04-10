#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
///오차 10^-9까진 맞게
int main()
{
	double A = 0.0, B = 0.0;
	cin >> A >> B;
	cout.precision(10);
	cout << A/B << endl;
	return 0;
}