#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <string>
using namespace std;
bool visit[1002][1002] = {};
char maps[1002][1002] = {};
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int main()
{
	int R, C = 0, sec = 0, flag = 0;
	scanf("%d %d", &R, &C);
	deque <pair <int, int >> J, F;
	for (int i = 1; i <= R; i++)
	{
		string s = "";
		cin >> s;
		for (int j = 1; j <= C; j++)
		{
			maps[i][j] = s[j - 1];

			if (maps[i][j] == 'J')
				J.push_back({ i, j });
			else if (maps[i][j] == 'F')
				F.push_back({ i, j });
		}
	}

	for (int i = 0; i <= C + 1; i++)
	{
		maps[0][i] = '.';
		maps[R + 1][i] = '.';
	}

	for (int i = 0; i <= R + 1; i++)
	{
		maps[i][0] = '.';
		maps[i][C + 1] = '.';
	}

	while (!J.empty())
	{
		int J_size = J.size();
		for (int i = 0; i < J_size; i++)
		{
			int x = J.front().first;
			int y = J.front().second;
			J.pop_front();
			if (maps[x][y] == 'F')
				continue;
			maps[x][y] = '.';
			visit[x][y] = 1;
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (maps[nx][ny] != '.' || visit[nx][ny])
					continue;

				if (nx > R || nx <= 0 || ny > C || ny <= 0 && maps[nx][ny] == '.')
				{
						flag = 1;
						sec += 1;
						break;
				}

				else if (nx > R || nx <= 0 || ny > C || ny <= 0 && maps[nx][ny] != '.')
					continue;
	
				J.push_back({ nx,ny });
				visit[nx][ny] = 1;
			}

			if (flag == 1)
				break;
		}

		if (flag == 1)
			break;

		int F_size = F.size();
		for (int i = 0; i < F_size; i++)
		{
			int x = F.front().first;
			int y = F.front().second;
			F.pop_front();
			maps[x][y] = 'F';

			
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if (maps[nx][ny] == '#' || maps[nx][ny] == 'F' )
					continue;

				if (nx > R || nx <= 0 || ny > C || ny <= 0)
					continue;

				F.push_back({ nx,ny });
				maps[nx][ny] = 'F';
			}
			if (flag == 2)
				break;
		}
		if (flag == 2)
			break;

		sec++;
	}

	if (flag == 0 ||flag == 2)
		printf("IMPOSSIBLE\n");

	else
		printf("%d\n", sec);
	return 0;
}