#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int N, K = 0;//수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)
	int cnt = 0;
	deque <int> maps;
	bool check[100001] = {};
	cin >> N >> K;
	maps.push_back(N);
	check[N] = 1;
	while (!maps.empty())
	{
		int t = maps.size();
		for (int i = 0; i < t; i++)
		{
			int now = maps.front();
			maps.pop_front();
			if (now == K)
			{
				cout << cnt << endl;
				return 0;
			}

			if (now-1 >= 0 && check[now - 1] == false)
			{
				check[now - 1] = 1;
				maps.push_back(now - 1);
			}

			if (now+1 <= 100000 && check[now + 1] == false)
			{
				check[now + 1] = 1;
				maps.push_back(now + 1);
			}

			if (now * 2 <= 100000 && check[now * 2] == false)
			{
				check[now * 2] = 1;
				maps.push_back(now * 2);
			}
		}
		cnt++;
	}
	return 0;
}