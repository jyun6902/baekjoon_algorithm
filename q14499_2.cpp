#include <iostream>
#include <cstring>
using namespace std;

int maps[21][21];
int dice[4][3];
int x, y = 0;
void rotate(int dir)
{
	if (dir == 1) //µ¿
	{
		int temp = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = temp;

		temp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = temp;

		temp = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = temp;

		y += 1;
	}

	else if (dir == 2)// ¼­
	{
		int temp = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = temp;

		temp = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = temp;

		temp = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = temp;

		y -= 1;
	}

	else if (dir == 3) // ºÏ
	{
		int temp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = temp;

		x -= 1;
	}

	else if (dir == 4) // ³²
	{
		int temp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = temp;

		x += 1;
	}


	if (maps[x][y] == 0)
		maps[x][y] = dice[3][1];
	else
	{
		dice[3][1] = maps[x][y];
		maps[x][y] = 0;
	}
}

int main()
{
	int N, M = 0, K=0, order=0;
	x = 0, y = 0;
	memset(maps, 0, sizeof(maps));
	memset(dice, 0, sizeof(dice));
	cin >> N >> M >> x>> y>> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> maps[i][j];
	}

	/*dice[0][1] = 2;
	dice[1][0] = 4;
	dice[1][1] = 1;
	dice[1][2] = 3;
	dice[2][1] = 5;
	dice[3][1] = 6;

	rotate(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << dice[i][j];
		cout << endl;
	}*/


	for (int i = 0; i < K; i++)
	{
		cin >> order;
		if (order == 1 )
		{
			if (y +1 >= M)
				continue;
			else
				rotate(1);
		}

		else if (order == 2)
		{
			if (y - 1 < 0)
				continue;
			else
				rotate(2);
		}

		else if (order == 3)
		{
			if (x - 1 < 0)
				continue;
			else
				rotate(3);
		}
		
		else if (order == 4)
		{
			if (x + 1 >= N)
				continue;
			else
				rotate(4);
		}

		cout << dice[1][1] << endl;
	}
	
	return 0;
}