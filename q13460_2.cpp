#include <iostream>
#include <cstring>

using namespace std;

int N, M = 0;
char maps[11][11];
int ox = 0, oy = 0;
int min_result = 987654321;

void cal(char maps[11][11], int rx, int ry, int bx, int by, int cnt, int dir)
{

	if (cnt > 10 || cnt >= min_result)
		return;

	char maps_copy[11][11];
	memset(maps_copy, 0, sizeof(maps_copy));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			maps_copy[i][j] = maps[i][j];
			if (maps[i][j] == 'R')
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

	if (dir == 1)// µ¿
	{
		if (ry > by)
		{
			int i = ry;
			maps_copy[rx][i] = '.';
			while (maps_copy[rx][i + 1] == '.')
			{
				i++;
			}
			ry = i;
			maps_copy[rx][i] = 'R';

			int j = by;
			maps_copy[bx][j] = '.';
			while (maps_copy[bx][j + 1] == '.')
			{
				j++;
			}
			by = j;
			maps_copy[bx][j] = 'B';

			if (j + 1 == i && i + 1 == oy && rx == ox && bx == ox)
				return;//BRO

			else if (j + 1 == oy && bx == ox)
				return;//BO

			else if (i + 1 == oy && rx == ox)
			{//RO
				if (min_result > cnt)
					min_result = cnt;
				return;
			}
		}

		else// ry< by
		{
			int j = by;
			maps_copy[bx][j] = '.';
			while (maps_copy[bx][j + 1] == '.')
			{
				j++;
			}
			by = j;
			maps_copy[bx][j] = 'B';

			int i = ry;
			maps_copy[rx][i] = '.';
			while (maps_copy[rx][i + 1] == '.')
			{
				i++;
			}
			ry = i;
			maps_copy[rx][i] = 'R';

			if (i + 1 == j && j + 1 == oy && rx == ox && bx == ox)//RBO
				return;

			if (j + 1 == oy && bx == ox)//BO
				return;

			else if (i + 1 == oy && rx == ox)//RO
			{
				if (min_result > cnt)
					min_result = cnt;
				return;
			}
		}//else
	}


	else if (dir == 2)// ¼­
	{
		if (ry > by)
		{
			int j = by;
			maps_copy[bx][j] = '.';
			while (maps_copy[bx][j - 1] == '.')
			{
				j--;
			}
			by = j;

			maps_copy[bx][j] = 'B';


			int i = ry;
			maps_copy[rx][i] = '.';
			while (maps_copy[rx][i - 1] == '.')
			{
				i--;
			}
			ry = i;

			maps_copy[rx][i] = 'R';


			if (j + 1 == i && j - 1 == oy && rx == ox && bx == ox)
				return;//OBR

			else if (j - 1 == oy && bx == ox)
				return;//OB

			else if (i - 1 == oy && rx == ox)
			{//OR
				if (min_result > cnt)
					min_result = cnt;
				return;
			}
		}

		else// (ry < by)
		{
			int i = ry;
			maps_copy[rx][i] = '.';
			while (maps_copy[rx][i - 1] == '.')
			{
				i--;
			}
			ry = i;

			maps_copy[rx][i] = 'R';

			int j = by;
			maps_copy[bx][j] = '.';
			while (maps_copy[bx][j - 1] == '.')
			{
				j--;
			}
			by = j;

			maps_copy[bx][j] = 'B';

			if (i + 1 == j && i - 1 == oy && rx == ox && bx == ox)
				return;//ORB

			else if (j - 1 == oy && bx == ox)
				return;//OB

			else if (i - 1 == oy && rx == ox)
			{//OR
				if (min_result > cnt)
					min_result = cnt;
				return;
			}
		}
	}//dir == 2

	else if (dir == 3)// ³²
	{
		if (rx > bx)
		{
			int i = rx;
			maps_copy[i][ry] = '.';
			while (maps_copy[i + 1][ry] == '.')
			{
				i++;
			}
			rx = i;
			maps_copy[i][ry] = 'R';

			int j = bx;
			maps_copy[j][by] = '.';
			while (maps_copy[j + 1][by] == '.')
			{
				j++;
			}
			bx = j;

			maps_copy[j][by] = 'B';

			if (j + 1 == i && i + 1 == ox && ry == oy && by == oy)
				return;

			else if (j + 1 == ox && by == oy)
				return;//BO

			else if (i + 1 == ox && ry == oy)
			{//RO
				if (min_result > cnt)
					min_result = cnt;
				return;
			}
		}

		else// rx< bx
		{
			int j = bx;
			maps_copy[j][by] = '.';
			while (maps_copy[j + 1][by] == '.')
			{
				j++;
			}
			bx = j;
			maps_copy[j][by] = 'B';

			int i = rx;
			maps_copy[i][ry] = '.';
			while (maps_copy[i + 1][ry] == '.')
			{
				i++;
			}
			rx = i;
			maps_copy[i][ry] = 'R';

			if (i + 1 == j && j + 1 == ox && ry == oy && by == oy)//RBO
				return;

			if (j + 1 == ox && by == oy)//BO
				return;

			else if (i + 1 == ox && ry == oy)//RO
			{
				if (min_result > cnt)
					min_result = cnt;
				return;
			}
		}//else
	}//dir==3


	else if (dir == 4)// ºÏ
	{
		if (rx > bx)
		{
			int j = bx;
			maps_copy[j][by] = '.';
			while (maps_copy[j - 1][by] == '.')
			{
				j--;
			}
			bx = j;
			maps_copy[j][by] = 'B';

			int i = rx;
			maps_copy[i][ry] = '.';
			while (maps_copy[i - 1][ry] == '.')
			{
				i--;
			}
			rx = i;
			maps_copy[i][ry] = 'R';

			if (j + 1 == i && j - 1 == ox && ry == oy && by == oy)
				return;//OBR

			else if (j - 1 == ox && by == oy)
				return;//OB

			else if (i - 1 == ox && ry == oy)
			{//OR
				if (min_result > cnt)
					min_result = cnt;
				return;
			}
		}

		else// (rx < bx)
		{
			int i = rx;
			maps_copy[i][ry] = '.';
			while (maps_copy[i - 1][ry] == '.')
			{
				i--;
			}
			rx = i;
			maps_copy[i][ry] = 'R';

			int j = bx;
			maps_copy[j][by] = '.';
			while (maps_copy[j - 1][by] == '.')
			{
				j--;
			}
			bx = j;

			maps_copy[j][by] = 'B';

			if (i + 1 == j && i - 1 == ox && ry == oy && by == oy)
				return;//ORB

			else if (j - 1 == ox && by == oy)
				return;//OB

			else if (i - 1 == ox && ry == oy)
			{//OR
				if (min_result > cnt)
					min_result = cnt;
				return;
			}
		}
	}//dir == 4

	if (maps_copy[rx][ry + 1] != '#' || maps_copy[bx][by + 1] != '#')
		cal(maps_copy, rx, ry, bx, by, cnt + 1, 1);

	if (maps_copy[rx][ry - 1] != '#' || maps_copy[bx][by - 1] != '#')
		cal(maps_copy, rx, ry, bx, by, cnt + 1, 2);

	if (maps_copy[rx + 1][ry] != '#' || maps_copy[bx + 1][by] != '#')
		cal(maps_copy, rx, ry, bx, by, cnt + 1, 3);

	if (maps_copy[rx - 1][ry] != '#' || maps_copy[bx - 1][by] != '#')
		cal(maps_copy, rx, ry, bx, by, cnt + 1, 4);
}

int main()
{
	memset(maps, 0, sizeof(maps));
	cin >> N >> M;
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

	cal(maps, rx, ry, bx, by, 1, 1);
	cal(maps, rx, ry, bx, by, 1, 2);
	cal(maps, rx, ry, bx, by, 1, 3);
	cal(maps, rx, ry, bx, by, 1, 4);
	if (min_result == 987654321)
		cout << "-1" << endl;
	else
		cout << min_result << endl;

	return 0;
}