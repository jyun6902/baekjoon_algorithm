#include <iostream>
using namespace std;
int s[1001] = { 0, };
int inc[1001] = { 1, };
int des[1001] = { 0, };

int main()
{
	int n = 0, j=0;
	cin >> n;

	des[n - 1] = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}



	for (int i = 0; i < n; i++)			//증가하는 값 따지기
	{
		int max = s[0];
		for ( j = 0; j < i + 1; j++)
		{
			if (max <= s[j] && max < s[i])
			{
				max = j;
				inc[max + 1] = inc[max] + 1;
			}
		}
		
		if (s[i] == s[i + 1])
			inc[i + 1] = inc[i];


		// cout << "i = " << i << " "<< inc[i] << endl;
	}

	//for (int i = n - 1; i >= 0; i--)			//증가하는 값 따지기
	//{
	//	if (s[i] == s[i - 1])
	//		des[i - 1] = des[i];

	//	else
	//	{
	//		int max = n - 1;
	//		for (int j = n - 1; j >= i; j--)
	//		{
	//			if (s[j] >= s[max] && s[j] < s[i - 1])
	//			{
	//				max = j;
	//			}
	//		}
	//		des[i - 1] = des[max] + 1;

	//	}

	//}

	for (int i = 0; i < n; i++)
	{
		cout << inc[i] << ' ';
	}
	cout << endl;
	//for (int i = n - 1; i >= 0; i--)
	//{
	//	cout << des[i] << ' ';
	//}
	//cout << endl;


	//int max = 2;
	//for (int i = 0; i < n; i++)
	//{
	//	if (max < des[i] + inc[i])
	//		max = des[i] + inc[i];
	//}
	//cout << max - 1 << endl;
	return 0;
}

