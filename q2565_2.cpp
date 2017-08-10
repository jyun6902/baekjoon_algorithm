#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
	int n = 0, max_a= 0;
	int line[501] = { 0 };
	deque <int> dq;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b = 0;
		cin >> a >> b;
		line[a] = b;
		if (max_a < a)
			max_a = a;
	}
	dq.push_back(-987654321);
	for (int i = 1; i <= max_a ;i++)
	{
		if (line[i] == 0)
			continue;
		
		else if (dq.back() < line[i])
			dq.push_back(line[i]);
		
		else
		{
			auto iter = lower_bound(dq.begin(), dq.end(), line[i]);
			*iter = line[i];
		}
	}

	cout << n -(dq.size() - 1) <<endl;
	return 0;
}