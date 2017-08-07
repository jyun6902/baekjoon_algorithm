#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0, x = 0;
	deque <int> dq;
	cin >> n;			// n = 포트 개수

	dq.push_back(-987654321);
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (dq.back() < x)
			dq.push_back(x);
		else
		{
			auto it = lower_bound(dq.begin(), dq.end(), x);	//lower_bound ; 지정한 값으로 들어온 값보다 크거나 같은 값을 가지는 원소의 위치를 반환
			*it = x;
		}
	}

	cout << dq.size()-1 << endl;		//처음에 dq에 -무한대 push
	return 0;
}