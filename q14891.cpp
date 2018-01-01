#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;
gets();
deque <int> arr[5];
deque <int> arr_copy[5];
void rotate(int who, int clockwise)//회전
{
	if (clockwise == 1)// closewise=1 시계
	{
		int x = arr[who].back();
		arr[who].pop_back();
		arr[who].push_front(x);
	}

	else //clockwise = -1 반시계
	{
		int x = arr[who].front();
		arr[who].pop_front();
		arr[who].push_back(x);
	}
}

int check(int who, int dir)//dir= 1 오른쪽 dir= -1 왼쪽
{
	if (who == 1 && dir == 1 && arr_copy[1][2] != arr_copy[2][6])
		return 2;

	if (who == 4 && dir == -1 && arr_copy[3][2] != arr_copy[4][6])
		return 3;

	if (who == 2 && dir == -1 && arr_copy[2][6] != arr_copy[1][2])
		return 1;

	if (who == 2 && dir == 1 && arr_copy[2][2] != arr_copy[3][6])
		return 3;

	if (who == 3 && dir == -1 && arr_copy[2][2] != arr_copy[3][6])
		return 2;

	if (who == 3 && dir == 1 && arr_copy[3][2] != arr_copy[4][6])
		return 4;

	return 0;
}


int main()
{
	int K = 0;//1 ≤ K ≤ 100
	vector <pair <int, int >> order[101];
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int n = 0;
			scanf("%1d", &n);
			arr[i].push_back(n);
		}
		arr_copy[i] = arr[i];
	}


	cin >> K;

	for (int i = 0; i < K; i++)//명령 입력받기
	{
		int who, dir = 0;
		cin >> who >> dir;
		order[i].push_back({ who, dir });
	}

	for (int j = 0; j < K; j++)
	{
		int visit[5] = {};
		int who = order[j].front().first;
		int dir = order[j].front().second;
		rotate(who, dir);
		visit[who] = dir;

		if (who == 1)
		{
			for (int i = 2; i <= 4; i++)
			{
				if (visit[i] == 0 && check(i, -1) != 0)
				{
					if (dir == 1)
						dir = -1;
					else
						dir = 1;

					rotate(i, dir);
					visit[i] = dir;
				}
				else
					break;
			}
		}

		else if (who == 4)
		{
			for (int i = 3; i >= 1; i--)
			{
				if (visit[i] == 0 && check(i, 1) != 0)
				{
					if (dir == 1)
						dir = -1;
					else
						dir = 1;

					rotate(i, dir);
					visit[i] = dir;
				}
				else break;
			}
		}

		else if (who == 2)
		{
			for (int i = 3; i <= 4; i++)
			{
				if (visit[i] == 0 && check(i, -1) != 0)/////////////////////고치기
				{
					if (dir == 1)
						dir = -1;
					else
						dir = 1;

					rotate(i, dir);
					visit[i] = dir;
				}
				else
					break;
			}

			if (visit[1] == 0 && check(2, -1) != 0)
			{
				if (visit[2] == 1)
					dir = -1;
				else
					dir = 1;

				rotate(1, dir);
				visit[1] = dir;
			}
		}
		/////////////////////
		else if (who == 3)
		{
			for (int i = 2; i >= 1; i--)
			{
				if (visit[i] == 0 && check(i, 1) != 0)
				{
					if (dir == 1)
						dir = -1;
					else
						dir = 1;

					rotate(i, dir);
					visit[i] = dir;
				}
				else break;
			}

			if (visit[4] == 0 && check(3, 1) != 0)
			{
				if (visit[3] == 1)
					dir = -1;
				else
					dir = 1;

				rotate(4, dir);
				visit[4] = dir;
			}
		}

		for (int i = 0; i < 5; i++)
			arr_copy[i] = arr[i];
	}

	int result = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (arr[i][0] == 1)//S극인 경우
			result += pow(2, i - 1);
	}

	cout << result << endl;
	return 0;
}