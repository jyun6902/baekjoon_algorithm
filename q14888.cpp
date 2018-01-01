#include <iostream>
using namespace std;

int N = 0;
int arr[101] = {};
int a, b, c, d = 0; // a= µ¡¼À b= »¬¼À c = °ö¼À d = ³ª´°¼À
long max_result = -1000000000, min_result = 1000000000;
void cal(int e, int  f, int g, int h, int cnt, long sum)
{
	if (cnt == N)
	{
		if (sum > max_result)
			max_result = sum;
		if (sum < min_result)
			min_result = sum;
		return;
	}

	if (e < a)
		cal(e + 1, f, g, h, cnt + 1, sum + arr[cnt]);

	if (f < b)
		cal(e, f + 1, g, h, cnt + 1, sum - arr[cnt]);

	if (g < c)
		cal(e, f, g + 1, h, cnt + 1, sum * arr[cnt]);

	if (h < d)
		cal(e, f, g, h + 1, cnt + 1, sum / arr[cnt]);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> a >> b >> c >> d;
	cal(0, 0, 0, 0, 1, arr[0]);

	cout << max_result << endl;
	cout << min_result << endl;
	return 0;
}