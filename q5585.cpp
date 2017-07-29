#include <iostream>
using namespace std;
int main()
{
	int N = 0, answer = 0;
	cin >> N;
	N = 1000 - N;
	while (N != 0)
	{
		if (N >= 500)
		{
			N -= 500;
			answer++;
		}

		if (N < 500 && N >= 100)
		{
			N -= 100;
			answer++;
		}

		if (N < 100 && N >= 50)
		{
			N -= 50;
			answer++;
		}

		if (N < 50 && N >= 10)
		{
			N -= 10;
			answer++;
		}

		if (N < 10 && N >= 5)
		{
			N -= 5;
			answer++;
		}

		if (N < 5 && N >= 1)
		{
			N -= 1;
			answer++;
		}
	}
	cout << answer << endl;
	return 0;
}