#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
/*연결 안되있는 경우 무한루트 돌게됨
반복조건이 1000회↓ 경우에는 for문이 while문 보다 더 빠름
1000이상일 경우 while문이 for문 보다 빠름
while() ->for()로 바꿔서 98%에서 시간초과 나는 것 해결
*/
int tube[100003] = {};
deque <vector<int>> dq;
vector <int>connect;
int main()
{
	int N, K, M = 0;	//N = 역의수, K= 한 하이퍼튜브가 서로 연결하는 역의 수, M= 하이퍼튜브의 개수
	cin >> N >> K >> M;	// (1 ≤ N ≤ 100,000, 1 ≤ K, M ≤ 1000)
	int a = 0;

	for (int i = 1; i <= N; i++)
		tube[i] = 987654321;

	tube[1] = 1;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			cin >> a;
			connect.push_back(a);
		}
		dq.push_back(connect);
		connect.clear();
	}

	while (!dq.empty())
	{
		int d_size = dq.size();
		for (int t = 0; t < d_size; t++)//while로 할 경우 시간초과
		{
			connect = dq.front();
			dq.pop_front();
			int flag = 0;
			int result = 987654321;
			int key = 0;

			for (int i = 0; i < K; i++)
			{
				if (tube[connect[i]] < result)//컨넥트된것 중에 가장 작은 것 찾음
				{
					result = tube[connect[i]];
					key = i;
					flag = 1;
				}
			}

			if (flag == 0)						//컨넥트 안됬을 경우 deque에 다시 넣음
				dq.push_back(connect);

			else
			{
				for (int j = 0; j < K; j++)
				{
					if (key == j)
						continue;

					if (tube[connect[key]] + 1 < tube[connect[j]])	//컨넥트 된것에서 더 작을 경우 업데이트
						tube[connect[j]] = tube[connect[key]] + 1;
				}
			}

		}//while d_size
		if (d_size == dq.size())		//더 이상 연결되지 않았을 경우
			break;
	}//while 

	if (tube[N] == 987654321)
		cout << "-1" << endl;

	else
		cout << tube[N] << endl;
	return 0;
}