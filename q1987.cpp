#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int R, C = 0;//1<=R, C<=20
char maps[21][21];
int max_result = 1;
bool check[26] = {};
int cal(int cnt, int dir, int x, int y)
{
	if (max_result < cnt)
		max_result = cnt;

	if (dir == 1 && x + 1 <= R)//µ¿
	{
		if (check[maps[x + 1][y] - 'A'] == false)
		{
			check[maps[x + 1][y] - 'A'] = true;
			for (int i = 1; i <= 4; i++)
				cal(cnt + 1, i, x + 1, y);
			
			check[maps[x + 1][y] - 'A'] = false;
		}

		else
			return max_result;
	}

	if (dir == 2 && x - 1 >= 1)//¼­
	{
		if (check[maps[x - 1][y] - 'A'] == false)
		{
			check[maps[x - 1][y] - 'A'] = true;
			for (int i = 1; i <= 4; i++)
				cal(cnt + 1, i, x - 1, y);
			
			check[maps[x - 1][y] - 'A'] = false;
		}
		else
			return max_result;
	}

	if (dir == 3 && y + 1 <= C)//³²
	{
		if (check[maps[x][y + 1] - 'A'] == false)
		{
			check[maps[x][y + 1] - 'A'] = true;
			for (int i = 1; i <= 4; i++)
				cal(cnt + 1, i, x, y + 1);
		
			check[maps[x][y + 1] - 'A'] = false;
		}

		else
			return max_result;
	}

	if (dir == 4 && y - 1 >= 1)//ºÏ
	{
		if (check[maps[x][y - 1] - 'A'] == false)
		{
			check[maps[x][y - 1] - 'A'] = true;
			for (int i = 1; i <= 4; i++)
				cal(cnt + 1, i, x, y - 1);
			
			check[maps[x][y - 1] - 'A'] = false;
		}

		else
			return max_result;
	}
}
int main()
{
	memset(maps, 0, sizeof(maps));
	cin >> R >> C;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			scanf("%1s", &maps[i][j]);
	}

	check[maps[1][1] - 'A'] = true;

	for (int i =  1 ; i<= 4 ; i++)
	cal(1, i, 1, 1);
	cout << max_result << endl;
	return 0;
}