#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	deque <char> dq_left;
	deque <char> dq_right;
	string s = "";
	int N = 0;
	cin >> s;
	
	for (int i = 0; i < s.length(); i++)
		dq_left.push_back(s[i]);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char order;
		cin >> order;
		if (order == 'L')
		{
			if (dq_left.empty())
				continue;
			char c = dq_left.back();
			dq_left.pop_back();
			dq_right.push_front(c);
		}

		else if (order == 'D')
		{
			if (dq_right.empty())
				continue;

			char c = dq_right.front();
			dq_right.pop_front();
			dq_left.push_back(c);
		}

		else if (order == 'B')
		{
			if (dq_left.empty())
				continue;
			dq_left.pop_back();
		}

		else if (order == 'P')
		{
			char p;
			cin >> p;
			dq_left.push_back(p);
		}
	}

	while (!dq_left.empty())
	{
		char p = dq_left.front();
		dq_left.pop_front();
		cout << p;
	}

	while (!dq_right.empty())
	{
		char p = dq_right.front();
		dq_right.pop_front();
		cout << p;
	}

	cout << endl;
	return 0;
}