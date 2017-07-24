#include <iostream>
#include <string>
using namespace std;

int main()
{
	string X, Y;
	int result = 0;
	int result_a = 10000;
	cin >> X >> Y;

	for (int i = 0; i <= Y.size() - X.size(); i++)
	{
		result = 0;
		for (int j = 0; j < X.size(); j++)
		{
			if (X[j] != Y[j + i])
				result++;
		}
		if (result_a > result)
			result_a = result;
	}

	cout << result_a << endl;
	return 0;
}