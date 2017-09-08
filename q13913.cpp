#include <iostream>
#include <deque>
#include <map>
using namespace std;

deque <int> maps;
map <int, int> from;
deque <int> save;
bool check[200001] = {};
int main()
{
	int N, K = 0;//수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)
	int cnt = 0;

	cin >> N >> K;
	maps.push_back(N);
	check[N] = 1;
	from[N] = N;	//도착점

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

				while (1)
				{
					save.push_back(from[now]);
					now = from[now];

					if (now == N)//K아니고 N!!
						break;
				}

				while (!save.empty())
				{
					int a = save.back();
					save.pop_back();
					cout << a << " ";
				}
				if (N == K)
					return 0;

				else
				cout << K << endl;
				return 0;
			}

			if (now - 1 >= 0 && check[now - 1] == false)
			{
				check[now - 1] = 1;
				from[now - 1] = now;
				maps.push_back(now - 1);

			}

			if (now + 1 <= 100000 && check[now + 1] == false)
			{
				check[now + 1] = 1;
				from[now + 1] = now;
				maps.push_back(now + 1);
			}

			if (now * 2 <= 100000 && check[now * 2] == false)
			{
				check[now * 2] = 1;
				from[2 * now] = now;
				maps.push_back(now * 2);
			}
		}
		cnt++;
	}
	return 0;
}