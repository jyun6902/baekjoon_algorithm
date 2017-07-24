#include <iostream>
using namespace std;
int step[301];
int d[301][3];
int max ( int a , int b)
{
	if ( a> b )
		return a;
	else
		return b;
}

int main()
{
	int n = 1;
	cin >> n;
	for (int i = 1 ; i <= n  ;i++)
		cin >>step[i];

	d[1][1] = step[1];
	for ( int i =2 ; i  <= n ; i++ )
	{
		d[i][1] = max(d[i-2][1],d[i-2][2])+step[i];	//계단 1 개 연속
		d[i][2] = d[i-1][1]+step[i];							//계단 2 개 연속
	}

		cout << max(d[n][1], d[n][2])<< "\n";
		return 0;
}
