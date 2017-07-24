#include <iostream>
#include <cstring>
#include <cmath>
using namespace std; 
int arr[6][65];

int main()
{
	int N = 0, temp = 0, digit = 0;
	cin >> N;	 //4<= N <=1,000,000
	temp = N;

	while (temp != 0)
	{
		temp /= 10;
		digit++;
	}
	memset(arr, sizeof(arr), 1);
	
	//(1) 4, 7 // 2 
	//(2) 44, 47, 74, 77, //4
	//(3) 444, 447, 474, 477, 744, 747, 774, 777 // 8
	//(4) 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7744, 7477, 7747, 7774, 7777 //16
	//(5) 32
	//(6) 64
	//arr[1][0] = 4, [1][1] = 7
	//[2][0] = 44 [2][1] = 47 [2][2] =74 [2][2]=77
	arr[1][0] = 4;
	arr[1][1] = 7;

	for (int i = 2; i <= digit; i++)
	{
		for (int j = 0; j < pow(2, i) / 2; j++)
			arr[i][j] = 4 * pow(10, i - 1) + arr[i - 1][j];

		int k = 0;
		for (int j = pow(2, i) / 2; j < pow(2, i); j++)
		{
			
			arr[i][j] = 7 * pow(10, i - 1) + arr[i - 1][k++];
		}
	}

	int k = pow(2, digit-1) - 1;
	
	if (arr[digit - 1][k] <= N && arr[digit][0] > N)
		cout << arr[digit - 1][k];	
	
	else
	{
		int k = pow(2, digit);
		for (int j = 0 ; j < pow(2, digit)-1; j++)
		{
			if (arr[digit][j] <= N && arr[digit][j + 1] > N)
			{
				cout << arr[digit][j];
				j = pow(2, digit);
			}

			else if (arr[digit][k- 1] < N)
			{
				cout << arr[digit][k-1];
				j = k;
			}
		}
	}

	return 0;
}