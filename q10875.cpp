#include <iostream>
#include <deque>
#include <cmath>
#include <climits>
using namespace std;
#define LLONG_MIN(X,Y) ((X) < (Y) ? (X) : (Y))   
#define LLONG_MAX(X,Y) ((X) > (Y) ? (X) : (Y))  

int main()
{
	long long  L = 0, N = 0;	//L= map 크기 (2L+1)// N=머리 방향 몇 번 회전하는지	
	long long sec = 0;
	long long t[1002] = { 0 };	//t초간 dir방향으로
	int dir = 0, flag = 0;
	long long min_k = 3000000000, k = 0;
	long long  x = 0, y = 0;
	char d[1001];

	deque <pair<pair<long long, long long >, pair<long long, long long >>> h, w;// 시작점_x, 시작점_y, 도착점_x, 도착점_y// h=세로 w=가로
	cin >> L >> N;

	for (long i = 1; i <= N; i++)
		cin >> t[i] >> d[i];
	t[N + 1] = 30000000000;

	for (long long  case_T = 1; case_T <= N + 1; case_T++)
	{
		min_k = 3000000000;

		if (flag == 1)
		{
			cout << sec << endl;
			return 0;
		}

		if ( dir == 0)	//동
		{
			if (!w.empty())	//가로선과 만날때
			{
				for (long long i = 0; i < w.size(); i++)
				{
					if (w[i].first.second == y && LLONG_MIN(w[i].first.first, w[i].second.first) >= x && LLONG_MIN(w[i].first.first, w[i].second.first) <= x + t[case_T])
					{
						k = abs(LLONG_MIN(w[i].first.first, w[i].second.first) - x);
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}
			}
			if (!h.empty())	//세로 선과 만날때
			{
				for (long long  i = 0; i < h.size() - 1; i++)
				{
					if (h[i].first.first >= x && h[i].first.first <= x + t[case_T] && LLONG_MIN(h[i].first.second, h[i].second.second) <= y && LLONG_MAX(h[i].first.second, h[i].second.second) >= y)
					{
						k = abs(h[i].first.first - x);
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}//for
			}

			if (x + t[case_T] > L)	//범위 넘어갈 때
			{
				k = abs(L + 1 - x); 
				min_k = LLONG_MIN(k, min_k);
				flag = 1;
			}

			if (flag == 1)
			{
				sec +=abs( min_k);
				break;
			}

			else if (flag == 0)					//이동했을 경우
			{
				w.push_back({ { x, y }, { x + t[case_T], y } });
				x += t[case_T];
				sec += t[case_T];
			}
		}//dir==0

		else if (dir == 2)	//서
		{
			if (!w.empty())	//가로선과 만날때
			{
				for (long long  i = 0; i < w.size(); i++)
				{
					if (w[i].first.second == y && LLONG_MAX(w[i].first.first, w[i].second.first) <= x && LLONG_MAX(w[i].first.first, w[i].second.first) >= x - t[case_T])
					{
						k = abs(x - LLONG_MAX(w[i].first.first, w[i].second.first)); 
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}
			}

			if (!h.empty())	//세로 선과 만날때
			{
				for (long long  i = 0; i < h.size() - 1; i++)
				{
					if (h[i].first.first >= x - t[case_T] && h[i].first.first <= x  && LLONG_MIN(h[i].first.second, h[i].second.second) <= y && LLONG_MAX(h[i].first.second, h[i].second.second) >= y)
					{
						k = abs(h[i].first.first - x);
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}//for
			}

			if ( x - t[case_T] < -L)	//범위 넘어갈 때
			{
				k = abs(-L - 1 - x);
				min_k = LLONG_MIN(k, min_k);
				flag = 1;
			}

			if (flag == 1)
			{
				sec += abs(min_k);
				break;
			}

			else if (flag == 0)					//이동했을 경우
			{
				w.push_back({ { x, y },{ x - t[case_T], y } });
				x -= t[case_T];
				sec += t[case_T];
			}
		}//dir==2

		else if ( dir == 3)	//북
		{
			if (!h.empty())	//세로선과 만날때
			{
				for (long long i = 0; i < h.size(); i++)
				{
					if (h[i].first.first == x && LLONG_MIN(h[i].first.second, w[i].second.second) >= y && LLONG_MIN(w[i].first.second, w[i].second.second) <= y + t[case_T])
					{
						k = abs(LLONG_MIN(h[i].first.second, h[i].second.second) - y);
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}
			}

			if (!w.empty())	//가로 선과 만날때
			{
				for (long long  i = 0; i < w.size() - 1; i++)
				{
					if (w[i].first.second >= y && w[i].first.second <= y + t[case_T] && LLONG_MIN(w[i].first.first, w[i].second.first) <= x && LLONG_MAX(w[i].first.first, w[i].second.first) >= x)
					{
						k = abs(w[i].first.second - y);//최소로 하는 값 찾기
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}//for
			}

			if (y + t[case_T] > L)	//범위 넘어갈 때
			{
				k = abs(L + 1 - y);
				min_k = LLONG_MIN(k, min_k);
				flag = 1;
			}

			if (flag == 1)
			{
				sec += abs(min_k);
				break;
			}

			else if (flag == 0)					//이동했을 경우
			{
				h.push_back({ { x, y },{ x, y + t[case_T] } });
				y += t[case_T];
				sec += t[case_T];
			}
		}//dir==3북

		else if ( dir == 1)	//남
		{
			if (!h.empty())	//세로선과 만날때
			{
				for (long long  i = 0; i < h.size(); i++)
				{
					if (h[i].first.first == x && LLONG_MAX(h[i].first.second, w[i].second.second) <= y && LLONG_MAX(w[i].first.second, w[i].second.second) <= y - t[case_T])
					{
						k = abs(y - LLONG_MAX(h[i].first.second, h[i].second.second));
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}
			}
			
			if (!w.empty())	//가로 선과 만날때
			{
				for (long long  i = 0; i < w.size() - 1; i++)
				{
					if (w[i].first.second <= y && w[i].first.second >= y - t[case_T] && LLONG_MIN(w[i].first.first, w[i].second.first) <= x && LLONG_MAX(w[i].first.first, w[i].second.first) >= x)
					{
						k = abs(w[i].first.second - y);//최소로 하는 값 찾기
						min_k = LLONG_MIN(k, min_k);
						flag = 1;
					}
				}//for
			}

			if (y - t[case_T] < -L)	//범위 넘어갈 때
			{
				k = abs(-L - 1 - y);
				flag = 1; 
				min_k = LLONG_MIN(k, min_k);
			}

			if (flag == 1)
			{
				sec += abs(min_k);
				break;
			}

			else if (flag == 0)					//이동했을 경우
			{
				h.push_back({ { x, y },{ x, y - t[case_T] } });
				y -= t[case_T];
				sec += t[case_T];
			}
		}//dir==1남

		if (d[case_T] == 'L')
			dir = (dir + 3) % 4;

		else if (d[case_T] == 'R')
			dir = (dir + 1) % 4;
	}

	if (flag == 0 && dir == 0)	//동
		sec += abs(L + 1 - x);
	else if (flag == 0 && dir == 1)	//남
		sec += abs(-L - 1 - y);
	else if (flag == 0 && dir == 2)//서
		sec += abs(-L - 1 - x);
	else if (flag == 0 && dir == 3)	//북
		sec += abs(L + 1 - y);

	cout << sec << endl;
	return 0;
}