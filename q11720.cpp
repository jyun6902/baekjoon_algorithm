#include <iostream>
using namespace std;
int main()
{
	char sen[100];
	int sen_int[100];
	int N = 0,result = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> sen[i];
		sen_int[i] = sen[i] - '0';
		result += sen_int[i];
	}
	
	cout << result <<endl;
	return 0;
}