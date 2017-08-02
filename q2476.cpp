#include <iostream>
using namespace std;
int max_2(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	int N = 0, max_result = 0, result =0;
	int a, b, c;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int flag = 0;
		cin >> a >> b >> c;
		
		if (a == b && a == c && b == c)
			result = 10000 + (a * 1000);
		else if (a == b || a == c)
			result = 1000 + (a * 100);
		else if (b == c)
			result = 1000 + (b * 100);
		else
			result = 100 * (max_2(a, max_2(b, c)));
		
		if (result > max_result)
			max_result = result;
	}
	cout << max_result << endl;
	return 0;
}