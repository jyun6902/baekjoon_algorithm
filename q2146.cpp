#include <iostream>	//다리 만들기
#include <cstring>
#include <deque>
using namespace std;
int N = 0;
int maps[103][103];
int maps_count[103][103];
int dis[103][103];
int main()
{
	cin >> N;
	memset(maps, 0, sizeof(maps));
	memset(maps_count, 0, sizeof(maps_count));
	deque <pair<int, int>> land;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> maps[i][j];
	}

	int connect = 0;		//나눠지는 영역 카운트
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (maps[i][j] == 1 && maps_count[i][j] == 0)
			{
				maps_count[i][j] = ++connect;	//후위연산 왜?connect++ (x) 
				land.push_back({ i,j });
				while (!land.empty())
				{
					int x = land.front().first;
					int y = land.front().second;
					land.pop_front();

					if (y < N && maps[x][y + 1] == 1 && maps_count[x][y + 1] == 0)		//동
					{
						maps_count[x][y + 1] = connect;
						land.push_back({ x, y + 1 });
					}
					if (y > 1 && maps[x][y - 1] == 1 && maps_count[x][y - 1] == 0)		//서
					{
						maps_count[x][y - 1] = connect;
						land.push_back({ x, y - 1 });
					}
					if (x < N && maps[x + 1][y] == 1 && maps_count[x + 1][y] == 0)		//남
					{
						maps_count[x + 1][y] = connect;
						land.push_back({ x + 1, y });
					}
					if (x > 1 && maps[x - 1][y] == 1 && maps_count[x - 1][y] == 0)		//북
					{
						maps_count[x - 1][y] = connect;
						land.push_back({ x - 1, y });
					}

				}	//while
			}		//if
		}
	}

	int result = -1;
	for (int cnt = 1; cnt <= connect; cnt++)	//maps에서 1인 부분 거리배열 0으로 만듬
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				dis[i][j] = -1;
				if (maps_count[i][j] == cnt)
				{
					land.push_back({ i,j });	//maps에서 1인부분 push
					dis[i][j] = 0;				//dis = 0
				}
			}
		}	//for i 

		while (!land.empty())					//maps에서 0인 부분 거리 재기
		{
			int x = land.front().first;
			int y = land.front().second;
			land.pop_front();

			if (y < N && dis[x][y + 1] == -1)		//동
			{
				dis[x][y + 1] = dis[x][y] + 1;
				land.push_back({ x, y + 1 });
			}
			if (y > 1 && dis[x][y - 1] == -1)		//서
			{
				dis[x][y - 1] = dis[x][y] + 1;
				land.push_back({ x, y - 1 });
			}
			if (x < N && dis[x + 1][y] == -1)		//남
			{
				dis[x + 1][y] = dis[x][y] + 1;
				land.push_back({ x + 1, y });
			}
			if (x > 1 && dis[x - 1][y] == -1)		//북
			{
				dis[x - 1][y] = dis[x][y] + 1;
				land.push_back({ x - 1, y });
			}
		}	//while

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (maps[i][j] == 1 && maps_count[i][j] != cnt)
				{
					if (result == -1 || dis[i][j] - 1 < result)
						result = dis[i][j] - 1;
				}
			}
		}
	/*	
		cout << "----------------------------------" << endl;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << dis[i][j] << " ";
			}
			cout << endl;
		}
		*/
	}
	
	cout << result << endl;
	return 0;
}