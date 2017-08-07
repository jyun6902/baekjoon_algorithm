#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	int N = 0;
	deque <int> line;
	cin >> N;

	line.push_back(-987654321);
	for (int i = 1; i <= N; i++)
	{
		int x = 0;
		cin >> x;
		if (line.back() < x)
			line.push_back(x);
		else
		{
			auto iter = lower_bound(line.begin(), line.end(), x);
			*iter = x;
		}
	}

	cout << N- (line.size() - 1)<< endl;
	return 0;
}