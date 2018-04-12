#include <iostream>
#include <cstdio>
#include <deque>
#include <cstring>

using namespace std;

int N, M = 0;
int maps[302][302] = {};
int visit[302][302] = {};
int next_maps[302][302] = {};
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 , 0 };

int main()
{

	scanf("%d %d", &N, &M);
	deque < pair <int, int >> dq;
	deque <pair <int, int >> check;
	int cnt = 0;
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &maps[i][j]);
			if (maps[i][j] != 0)
			{
				cnt++;
				dq.push_back({ i,j });
				if (check.empty())
					check.push_back({ i,j });
			}
		}
	}
	
	while (!dq.empty())
	{
		memset(visit, 0, sizeof(visit));
		int check_size = 0;
		while (!check.empty())
		{
			int x = check.front().first;
			int y = check.front().second;

			check.pop_front();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 1 || nx > N || ny < 1 || ny > M || maps[nx][ny] == 0 || visit[nx][ny] == 1)
					continue;

				visit[nx][ny] = 1;
				check.push_back({ nx, ny });
				check_size++;
			}
		}

		if (check_size < dq.size())
			break;

		int dq_size = dq.size();
		for (int p = 0; p < dq_size; p++)
		{
			int x = dq.front().first;
			int y = dq.front().second;

			dq.pop_front();
			int num = 0;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 1 || nx > N || ny < 1 || ny > M) 
					continue;
				if (maps[nx][ny] == 0 )
				num++;

			}
			if (maps[x][y] - num > 0)
			{
				next_maps[x][y] = maps[x][y] - num;
				dq.push_back({ x,y });
			}
		}
		deque <pair <int, int >> dq_cp;
		dq_cp = dq;
		memset(maps, 0, sizeof(maps));
		while (!dq_cp.empty())//maps¿¡ º¹»ç
		{
			int x = dq_cp.front().first;
			int y = dq_cp.front().second;
			dq_cp.pop_front();
			maps[x][y] = next_maps[x][y];

			if (check.empty())
				check.push_back({ x,y });
		}
		memset(next_maps, 0, sizeof(next_maps));

		

		result++;
	}//while dq.empty()
	
	if (dq.empty())
		result = 0;
	
	printf("%d\n", result);
	return 0;
}