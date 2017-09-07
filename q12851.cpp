#include <iostream>
#include <deque>
#include <map>
using namespace std;

int main()
{
	int N, K = 0;//수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)
	int now = 0, cnt = 0, ret = 987654321;
	map <int, int> arr;
	bool check[100001] = {};
	deque <pair<int, int>> maps;
	cin >> N >> K;
	maps.push_back({ N,0 });

	while (!maps.empty())
	{
		now = maps.front().first;
		cnt = maps.front().second;

		maps.pop_front();
		check[now] = 1;
		if (now == K)
		{
			arr[cnt]++;
			if (ret > cnt)
				ret = cnt;
		}

		if (now - 1 >= 0 && check[now - 1] == false)
			maps.push_back({ now - 1, cnt + 1 });

		if (now + 1 <= 100000 && check[now + 1] == false)
			maps.push_back({ now + 1, cnt + 1 });

		if (now * 2 <= 100000 && check[now * 2] == false)
			maps.push_back({ now * 2, cnt + 1 });
	}

	cout << ret << endl;
	cout << arr[ret] << endl;
	return 0;
}