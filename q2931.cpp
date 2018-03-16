#include <iostream>
#include <cstring>
#include <cstdio>
#include <deque>
using namespace std;
char maps[27][27];
int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, 1, -1, 0 , 0 };
bool visit[27][27];
int R, C = 0;
//Block ; '|', '-','+','1','2','3','4'
//1:┌ //2: └ //3:┘ //4: ┐
//visit체크하는게 중요! 재귀터짐(메모리초과)
deque <pair<int, int>> dq;
bool dir[5] = {}; // 동, 서, 남, 북
void shape(int x, int y)
{
	if (maps[x][y + 1] == '-' || maps[x][y + 1] == '+' || maps[x][y + 1] == '3' || maps[x][y + 1] == '4')
		dir[1] = true;
	else
		dir[1] = false;

	if (maps[x][y - 1] == '-' || maps[x][y - 1] == '+' || maps[x][y - 1] == '1' || maps[x][y - 1] == '2')
		dir[2] = true;
	else
		dir[2] = false;

	if (maps[x + 1][y] == '|' || maps[x + 1][y] == '+' || maps[x + 1][y] == '2' || maps[x + 1][y] == '3')
		dir[3] = true;
	else
		dir[3] = false;

	if (maps[x - 1][y] == '|' || maps[x - 1][y] == '+' || maps[x - 1][y] == '1' || maps[x - 1][y] == '4')
		dir[4] = true;
	else
		dir[4] = false;
}

void cal(int x, int y, int dir)
{
	visit[x][y] = 1;
	if (!dq.empty())
		return;

	if (maps[x][y] == '|')
	{
		if (dir == 3 && visit[x+1][y] == 0)
			cal(x + 1, y, 3);
		else if (dir == 4 && visit[x - 1][y] == 0)
			cal(x - 1, y, 4);
	}

	else if (maps[x][y] == '-')
	{
		if (dir == 1 && visit[x][y+1] == 0)
			cal(x, y + 1, 1);
		else if (dir == 2 && visit[x][y-1] == 0)
			cal(x, y - 1, 2);
	}

	else if (maps[x][y] == '+')
	{
		if ( visit[x][y+1] == 0)
		cal(x, y + 1, 1);

		if ( visit[x][y-1] == 0)
		cal(x, y - 1, 2);
		if (visit[x+1][y] == 0)
		cal(x + 1, y, 3);
		if ( visit[x-1][y] == 0)
		cal(x - 1, y, 4);
	}

	else if (maps[x][y] == '1')//┌
	{
		if (dir == 2 && visit[x + 1][y] == 0)
			cal(x + 1, y, 3);
		else if (dir == 4 && visit[x][y + 1] == 0)
			cal(x, y + 1, 1);
	}

	else if (maps[x][y] == '2')//└
	{
		if (dir == 2 && visit[x-1][y] == 0)
			cal(x - 1, y, 4);
		else if (dir == 3 && visit[x][y + 1] == 0)
			cal(x, y + 1, 1);
	}

	else if (maps[x][y] == '3')//┘
	{
		if (dir == 1 && visit[x-1][y] == 0)
			cal(x - 1, y, 4);
		else if (dir == 3 && visit[x][y - 1] == 0)
			cal(x, y - 1, 2);
	}

	else if (maps[x][y] == '4')// ┐
	{
		if (dir == 1 && visit[x+1][y] == 0)
			cal(x + 1, y, 3);
		else if (dir == 4 && visit[x][y - 1] == 0)
			cal(x, y - 1, 2);
	}

	else if (maps[x][y] == '.')
	{
		if (x <= R && x >= 1 && y <= C && y >= 1)
			dq.push_back({ x,y });
		
			return;
	}

}

int main()
{
	int mx, my, zx, zy = 0;
	memset(maps, 0, sizeof(maps));
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			scanf("%1s", &maps[i][j]);
			if (maps[i][j] == 'M')
			{
				mx = i;
				my = j;			
			}

			else if (maps[i][j] == 'Z')
			{
				zx = i;
				zy = j;
			}
		}
	}

	for (int i = 0; i <= R + 1; i++)
	{
		maps[i][0] = '.';
		maps[i][C + 1] = '.';
	}

	for (int j = 0; j <= C + 1; j++)
	{
		maps[0][j] = '.';
		maps[R + 1][j] = '.';
	}
	int flag = 0;

	if (maps[zx][zy-1] == '.' && maps[zx][zy + 1] == '.'&& maps[zx+1][zy] == '.' && maps[zx-1][zy] == '.')
	maps[zx][zy] = '+';


	if (maps[mx][my - 1] == '.' && maps[mx][my + 1] == '.'&& maps[mx + 1][my] == '.' && maps[mx - 1][my] == '.')
	{
		maps[mx][my] = '+';
		flag = 1;
	}

	if (flag == 0)
	{
		for (int i = 1; i <= 4; i++)
		{
			if (maps[mx + dx[i]][my + dy[i]] != '.')
			{
				cal(mx + dx[i], my + dy[i], i);
				break;
			}
		}
	}

	else //if (flag == 0)//M =근처에 아무것도 없음
	{
		for (int i = 1; i <= 4; i++)
		{
			if (maps[zx + dx[i]][zy + dy[i]] != '.')
			{
				cal(zx + dx[i], zy + dy[i], i);
				break;
			}
		}
	}

	int x = dq.front().first;
	int y = dq.front().second;
	dq.pop_front();

	cout << x << " " << y << " ";
	shape(x, y);

	if (dir[1] == 1 && dir[2] == 1 && dir[3] == 1 && dir[4] == 1)
		cout << "+" << endl;

	else if (dir[1] == 0 && dir[2] == 0 && dir[3] == 1 && dir[4] == 1)
		cout << "|" << endl;

	else if (dir[1] == 1 && dir[2] == 1 && dir[3] == 0 && dir[4] == 0)
		cout << "-" << endl;

	else if (dir[1] == 1 && dir[2] == 0 && dir[3] == 1 && dir[4] == 0)
		cout << "1" << endl;

	else if (dir[1] == 1 && dir[2] == 0 && dir[3] == 0 && dir[4] == 1)
		cout << "2" << endl;

	else if (dir[1] == 0 && dir[2] == 1 && dir[3] == 0 && dir[4] == 1)
		cout << "3" << endl;

	else if(dir[1] == 0 && dir[2] == 1 && dir[3] == 1 && dir[4] == 0)
		cout << "4" << endl;

	return 0;
}