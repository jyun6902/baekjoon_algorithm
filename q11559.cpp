/*
스택 ; LIFO (Last In First Out) 후입선출
큐 : FIFO ( First In First Out) 선입선출
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char maps[14][8];
int visit[14][8];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
void down()
{
	for (int j = 1; j <= 6; j++)
	{
		queue <char> q1;
		for (int i = 12; i > 0; i--)
		{
			if (maps[i][j] != '.')
			{
				q1.push(maps[i][j]);
				maps[i][j] = '.';
			}
		}

		int k = 12;
		while (!q1.empty())
		{
			maps[k--][j] = q1.front();
			q1.pop();
		}
	}
}

int main()
{
	memset(maps, 0, sizeof(maps));
	memset(visit, 0, sizeof(visit));
	int cnt = 0;
	for (int i = 1; i <=12; i++)
	{
		for (int j = 1; j <= 6; j++)
			cin >> maps[i][j];
	}

	down();
	while (1)
	{
		int flag = 0;
		for (int i = 12 ; i > 0; i--)
		{
			for (int j = 1 ; j <= 6; j++)
			{
				if (maps[i][j] != '.' && visit[i][j] != 1)
				{
					queue < pair<int, int >> q1;
					queue < pair<int, int >> q2;
					visit[i][j] = 1;
					q1.push({ i, j });
					q2.push({ i, j });

					while (!q1.empty())
					{
						queue <pair<int, int>> t1;
						t1= q1;
						q1.pop();
						for (int a = 0; a < 4; a++)
						{
							int x = t1.front().first + dx[a];
							int y = t1.front().second + dy[a];
							if (maps[x][y] == maps[i][j] && visit[x][y] != 1)
							{
								visit[x][y] = 1;
								q1.push({ x ,y });
								q2.push({ x ,y });
							}
						}
					}//while !q1.empty

					if (q2.size() >= 4)
					{
						flag = 1;
						while (!q2.empty())
						{
							int x = q2.front().first;
							int y = q2.front().second;
							q2.pop();
							maps[x][y] = '.';
						}
					}//if q2.size>=4
				}//if
			}//for j
		}//for i 

		if (flag == 1)
		{
			cnt++;
			down();
			memset(visit, 0, sizeof(visit));
		}
		else
			break;
	}//while 1

	cout << cnt << endl;
	return 0;
}