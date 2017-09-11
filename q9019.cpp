#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int T = 0, A = 0, B = 0;//T=테스트 케이스 개수 //A=레지스터의 초기 값 //B=최종 값
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> A >> B;
		int next = 0, flag = 0;
		char letter;
		deque <int> dq;
		deque <char> save;
		char how[10005];
		int from[10005] = {};
		bool check[10005] = {};
		
		memset(how, 0, sizeof(how));
		dq.push_back(A);
		check[A] = 1;
		from[A] = B;	//도착점
		
		while (!dq.empty())
		{
			int d_size = dq.size();
			for (int i = 0; i < d_size; i++)
			{
				int now = dq.front();
				dq.pop_front();

				if (now == B)
				{
					flag = 1;
					while (1)
					{
						save.push_back(how[now]);
						now = from[now];

						if (now == B)
							break;
					}
					save.pop_back();//마지막에 null값들어감

					while (!save.empty())
					{
						char a = save.back();
						save.pop_back();
						cout << a;
					}

					cout << endl;
					dq.clear();
					break;
				}

				if (flag == 1)
					break;

				next = 2*now;//D
				if (next > 9999)
					next %= 10000;
				
				if (check[next] == false)
				{
					dq.push_back(next);
					how[next] = 'D';
					from[next] = now;
					check[next] = true;
				}

				next = now - 1;//S
				if (now == 0)
					next = 9999;

				if (check[next] == false)
				{
					dq.push_back(next);
					how[next] = 'S';
					from[next] = now;
					check[next] = true;
				}

				int k = now / 1000;		//L
				next = (now%1000) *10 + k;
				if (check[next] == false)
				{
					dq.push_back(next);
					how[next] = 'L';
					from[next] = now;
					check[next] = true;
				}

				k = now % 10;			//R
				next = (now / 10) + (k * 1000);
				if (check[next] == false)
				{
					dq.push_back(next);
					how[next] = 'R';
					from[next] = now;
					check[next] = true;
				}
			}//for
		}//while
	}
	return 0;
}