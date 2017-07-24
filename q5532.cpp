#include <iostream>
using namespace std;

int main()
{
	int L, A, B, C, D = 0;
	int result_A, result_B;
	cin >> L >> A >> B >> C >> D;
	
	result_A = A / C;
	result_B = B / D;
	if (A%C != 0)
		result_A += 1;

	if (B%D != 0)
		result_B += 1;

	if (result_A > result_B)
		cout << L - result_A << endl;

	else
		cout << L - result_B << endl;

	return 0;
}