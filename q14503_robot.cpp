#include <iostream>
#include <cstring>
using namespace std;

int N, M = 0;	//세로 N 가로 M
int map[52][52];
int wash[52][52];
int r, c, d = 0;

int check(int x, int y, int dir)	//dir = 바라보는 방향
{
	wash[x][y] = 1;

	if (wash[x][y + 1] != 0 && wash[x][y - 1] != 0 && wash[x + 1][y] != 0 && wash[x - 1][y] != 0)
	{
		if (dir == 0)	//북쪽 바라봄
		{
			if (map[x + 1][y] == 1)
				return 0;

			else
			{
				x++;
				return check(x, y, 0);
			}
		}

		else if (dir == 1)	//동쪽 바라봄
		{
			if (map[x][y - 1] == 1)
				return 0;
			else
			{
				y--;
				return check(x, y, 1);
			}
		}


		else if (dir == 2)	//남쪽 바라봄
		{
			if (map[x - 1][y] == 1)
				return 0;
			else
			{
				x--;
				return check(x, y, 2);
			}
		}


		else if (dir == 3)	//서쪽 바라봄
		{
			if (map[x][y + 1] == 1)
				return 0;
			else
			{
				y++;
				return check(x, y, 3);
			}

		}
	}





	if (dir == 0)	//북쪽바라봄
	{
		y--;
		if (wash[x][y] == 0 && map[x][y] == 0)//왼쪽 비어있다면
		{
			return check(x, y, 3);	//바라보는 방향
		}

		else // if (wash[x][y - 1] != 0)//청소할 방향 없다면
		{
			y++;
			return check(x, y, 3);
		}

	}

	else if (dir == 1)	//동
	{
		x--;
		if (wash[x][y] == 0 && map[x][y] == 0)
		{
			return check(x, y, 0);
		}

		else //if (wash[x][y - 1] != 0)//청소할 방향 없다면
		{
			x++;
			return check(x, y, 0);
		}
	}

	else if (dir == 2)	//남
	{
		y++;
		if (wash[x][y] == 0 && map[x][y] == 0)
		{
			return check(x, y, 1);
		}

		else //if (wash[x][y - 1] != 0)//청소할 방향 없다면
		{
			y--;//////////////////////////
			return check(x, y, 1);
		}
	}

	else if (dir == 3)  //서
	{
		x++;
		if (wash[x][y] == 0 && map[x][y] == 0)
		{
			return check(x, y, 2);
		}

		else
		{
			x--;
			return check(x, y, 2);////////
		}
	}

}


int main()
{
	cin >> N >> M;
	int result = 0;

	memset(map, 0, sizeof(map));
	memset(wash, 0, sizeof(wash));

	cin >> r >> c >> d;	//청소기가 있는 좌표, 바라보는 방향
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				wash[i][j] = -1;
		}
	}


	check(r, c, d);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{

			if (wash[i][j] == 1)
				result++;
		}
	}
	cout << result;
	return 0;
}