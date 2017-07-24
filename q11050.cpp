#include <iostream>
using namespace std;

int main()
{
	int N, K;
	int result = 1,result_a=1;
	cin >> N >> K;
	
	for (int i = 0; i < K; i++)
	{
		result *= (N - i);
		result_a *= i + 1;
	}
	cout << result/result_a; 

	return 0;
}
