#include <iostream>
using namespace std;

int main()
{
	double R = 0.0;
	cin >> R;

	cout << fixed;
	cout.precision(6);
	cout << 3.14159265358979*R*R << endl;
	cout << 2 *R*R;

	return 0;
}