#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
int N, M = 0;
int ox, oy = 0;
int result = 987654321;

void cal(int rx, int ry, int bx, int by, char maps_cp[12][12], int dir, int cnt)
{
	if (cnt > 10)
		return;

	char maps_ex[12][12] = {};
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			maps_ex[i][j] = maps_cp[i][j];
			if (maps_ex[i][j] == 'R')
			{
				rx = i;
				ry = j;
			}

			else if (maps_ex[i][j] == 'B')
			{
				bx = i;
				by = j;
			}
		}
	}

	if (dir == 1)// µ¿
	{
		if (by < ry)
		{
			maps_ex[rx][ry] = '.';
			while (ry != M)
			{
				if (maps_ex[rx][ry + 1] == '.')
					ry++;
				else
					break;
			}
			maps_ex[rx][ry] = 'R';
			////////////////////////////
			maps_ex[bx][by] = '.';
			while (by != M)
			{
				if (maps_ex[bx][by + 1] == '.')
					by++;
				else
					break;
			}
			maps_ex[bx][by] = 'B';
			//////////////////////////

			if (maps_ex[bx][by + 1] == 'O')
				return;// BO

			if (maps_ex[rx][ry + 1] == 'O')
			{//RO
				if (maps_ex[bx][by + 2] == 'O') // BRO
					return;
				else
				{
					if (result > cnt)
						result = cnt;
					return;
				}
			}
		}

		else//by>ry
		{
			maps_ex[bx][by] = '.';
			while (by != M)
			{
				if (maps_ex[bx][by + 1] == '.')
					by++;
				else
					break;
			}
			maps_ex[bx][by] = 'B';
			//////////////////////////
			maps_ex[rx][ry] = '.';
			while (ry != M)
			{
				if (maps_ex[rx][ry + 1] == '.')
					ry++;
				else
					break;
			}
			maps_ex[rx][ry] = 'R';
			////////////////////////////

			if (maps_ex[bx][by + 1] == 'O')
				return;

			if (maps_ex[rx][ry + 1] == 'O')
			{

				if (result > cnt)
					result = cnt;
				return;
			}
		}
	}//dir == 1 µ¿


	else if (dir == 2)// ¼­
	{
		if (by < ry)
		{
			maps_ex[bx][by] = '.';
			while (by != 1)
			{
				if (maps_ex[bx][by - 1] == '.')
					by--;
				else
					break;
			}
			maps_ex[bx][by] = 'B';
			//////////////////////////
			maps_ex[rx][ry] = '.';
			while (ry != 1)
			{
				if (maps_ex[rx][ry - 1] == '.')
					ry--;
				else
					break;
			}
			maps_ex[rx][ry] = 'R';
			////////////////////////////

			if (maps_ex[bx][by - 1] == 'O')
				return;//OB

			if (maps_ex[rx][ry - 1] == 'O')
			{//ORB
				if (result > cnt)
					result = cnt;
				return;

			}
		}

		else//by>ry
		{
			maps_ex[rx][ry] = '.';
			while (ry != 1)
			{
				if (maps_ex[rx][ry - 1] == '.')
					ry--;
				else
					break;
			}
			maps_ex[rx][ry] = 'R';
			////////////////////////////
			maps_ex[bx][by] = '.';
			while (by != 1)
			{
				if (maps_ex[bx][by - 1] == '.')
					by--;
				else
					break;
			}
			maps_ex[bx][by] = 'B';
			//////////////////////////


			if (maps_ex[bx][by - 1] == 'O')
					return;

			if (maps_ex[rx][ry - 1] == 'O')
			{
				if (maps_ex[bx][by - 2] == 'O') // ORB
					return;

				if (result > cnt)
					result = cnt;
				return;

			}
		}
	}//dir == 2 ¼­

	else if (dir == 3)// ³²
	{
		if (bx < rx)
		{
			maps_ex[rx][ry] = '.';
			while (rx != N)
			{
				if (maps_ex[rx + 1][ry] == '.')
					rx++;
				else
					break;
			}
			maps_ex[rx][ry] = 'R';
			////////////////////////////
			maps_ex[bx][by] = '.';
			while (bx != N)
			{
				if (maps_ex[bx + 1][by] == '.')
					bx++;
				else
					break;
			}
			maps_ex[bx][by] = 'B';
			//////////////////////////

			if (maps_ex[bx + 1][by] == 'O')
				return;// BO

			if (maps_ex[rx + 1][ry] == 'O')
			{//RO
				if (maps_ex[bx + 2][by] == 'O') // BRO
					return;
				else
				{
					if (result > cnt)
						result = cnt;
					return;
				}
			}
		}

		else//bx>rx
		{
			maps_ex[bx][by] = '.';
			while (bx != N)
			{
				if (maps_ex[bx + 1][by] == '.')
					bx++;
				else
					break;
			}
			maps_ex[bx][by] = 'B';
			//////////////////////////
			maps_ex[rx][ry] = '.';
			while (rx != N)
			{
				if (maps_ex[rx + 1][ry] == '.')
					rx++;
				else
					break;
			}
			maps_ex[rx][ry] = 'R';
			////////////////////////////

			if (maps_ex[bx + 1][by] == 'O')
				return;

			if (maps_ex[rx + 1][ry] == 'O')
			{

				if (result > cnt)
					result = cnt;
				return;
			}
		}
	}//dir == 3 ³²


	else if (dir == 4)// ºÏ
	{
		if (bx < rx)
		{
			maps_ex[bx][by] = '.';
			while (bx != 1)
			{
				if (maps_ex[bx - 1][by] == '.')
					bx--;
				else
					break;
			}
			maps_ex[bx][by] = 'B';
			//////////////////////////
			maps_ex[rx][ry] = '.';
			while (rx != 1)
			{
				if (maps_ex[rx - 1][ry] == '.')
					rx--;
				else
					break;
			}
			maps_ex[rx][ry] = 'R';
			////////////////////////////

			if (maps_ex[bx - 1][by] == 'O')
				return;//OB

			if (maps_ex[rx - 1][ry] == 'O')
			{//ORB
				if (result > cnt)
					result = cnt;
				return;

			}
		}

		else//bx>rx
		{
			maps_ex[rx][ry] = '.';
			while (rx != 1)
			{
				if (maps_ex[rx - 1][ry] == '.')
					rx--;
				else
					break;
			}
			maps_ex[rx][ry] = 'R';
			////////////////////////////
			maps_ex[bx][by] = '.';
			while (bx != 1)
			{
				if (maps_ex[bx - 1][by] == '.')
					bx--;
				else
					break;
			}
			maps_ex[bx][by] = 'B';
			//////////////////////////

			if (maps_ex[bx - 1][by] == 'O')
				return;

			if (maps_ex[rx - 1][ry] == 'O')
			{
				if (maps_ex[bx - 2][by] == 'O') // ORB
					return;

				if (result > cnt)
					result = cnt;
				return;


			}
		}
	}//dir == 4 ºÏ

	cal(rx, ry, bx, by, maps_ex, 1, cnt + 1);
	cal(rx, ry, bx, by, maps_ex, 2, cnt + 1);
	cal(rx, ry, bx, by, maps_ex, 3, cnt + 1);
	cal(rx, ry, bx, by, maps_ex, 4, cnt + 1);
}


int main()
{
	char maps[12][12] = {};
	scanf("%d %d", &N, &M);
	int rx, ry, bx, by = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1s", &maps[i][j]);
			if (maps[i][j] == 'O')
			{
				ox = i;
				oy = j;
			}

			else if (maps[i][j] == 'R')
			{
				rx = i;
				ry = j;
			}

			else if (maps[i][j] == 'B')
			{
				bx = i;
				by = j;
			}
		}
	}
	//cal(int rx, int ry, int bx, int by, char maps_cp[12][12], int dir, int cnt)
	cal(rx, ry, bx, by, maps, 0, 0);
	if (result == 987654321)
		result = -1;
	printf("%d\n", result);
	return 0;
}