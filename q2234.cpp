/*
비트 연산 6&4==4 할때
(6&4)==4로 꼭 괄호 해줘야함!! 중요
C++에서는 &,|,^ 등의 비트 연산자의 우선순위는 ==혹은 != 등의 비교연산자 보다 낮다.
*/
#include <iostream>
#include <deque>
#include <bitset>
#include <cstring>
using namespace std;
int maps[52][52];	//1=서쪽벽 2=북쪽벽 4=동쪽벽 8=남쪽벽
int maps_count[52][52];
int maps_size[52][52];
deque <pair<int, int>> check;
int main()
{
	int n, m;
	int cnt = 0,max_size= 0;
	memset(maps, 0, sizeof(maps));
	memset(maps_count, 0, sizeof(maps_count));
	memset(maps_size, 0, sizeof(maps_size));
	cin >> n >> m;	//n = 열  m= 행
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
		}
	}

	for (int i = 0; i < m; i++)		//영역 count
	{
		for (int j = 0; j < n; j++)
		{
			if (maps_count[i][j] == 0)
			{
				maps_count[i][j] = ++cnt;
				check.push_back({ i,j });

				while (!check.empty())
				{
					int x = check.front().first;
					int y = check.front().second;
					int now = maps[x][y] ^ 15;
					check.pop_front();

					if (y < n - 1 && maps_count[x][y + 1] == 0 && ((now & 4) == 4))		//동
					{
						check.push_back({ x, y + 1 });
						maps_count[x][y + 1] = cnt;
					}

					if (y > 0 && ((now & 1) == 1) && maps_count[x][y - 1] == 0)			//서
					{
						check.push_back({ x, y - 1 });
						maps_count[x][y - 1] = cnt;
					}

					if (x < m - 1 && ((now & 8) == 8) && maps_count[x + 1][y] == 0)		//남
					{
						check.push_back({ x + 1, y });
						maps_count[x + 1][y] = cnt;
					}

					if (x > 0 && ((now & 2) == 2) && maps_count[x - 1][y] == 0)			//북
					{
						check.push_back({ x - 1, y });
						maps_count[x - 1][y] = cnt;
					}
				}//while
			}//if
		}
	}
	
	for (int k = 1; k <= cnt; k++)		//최대 크기 구하는 법
	{
		int size_k = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (maps_count[i][j] == k)
					size_k++;
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (maps_count[i][j] == k)
					maps_size[i][j] = size_k;//maps에 사이즈로 저장
			}
		}

		if (size_k > max_size)
			max_size = size_k;
	}

	int ans = 0, size_j = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maps_count[i][j] != maps_count[i][j + 1])
			{
				size_j = maps_size[i][j] + maps_size[i][j + 1];

				if (ans < size_j)
					ans = size_j;
			}

			if (maps_count[i][j] != maps_count[i+1][j])
			{
				size_j = maps_size[i][j] + maps_size[i + 1][j];

				if (ans < size_j)
					ans = size_j;
			}
		}

	}

	cout << cnt << endl;
	cout << max_size << endl;
	cout << ans << endl;
	return 0;
}