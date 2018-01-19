#include <iostream>
#include <vector>
using namespace std;

int N, S = 0; // 1≤N≤20, |S|≤1,000,000
vector <int > arr;
int cnt = 0;
void cal(int sum, int now)
{
	if (now == N)
	{

		if (S == sum)
			cnt++;
	
		return;
	}
	
	cal(sum+arr[now], now + 1);
	cal(sum , now + 1);
}

int main()
{
	cin >> N >> S; //N= 정수의 갯수 S= 합
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		arr.push_back(n);
	}
	//cal(arr[0], 1);
	//cal(0, 1);
	cal(0, 0);
	if (S == 0)
		cnt--;
	cout << cnt << endl;

	return 0;
}