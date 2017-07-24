#include <iostream>
#include <cstring>
using namespace std;
int map[21][21];
int direction[1000];
int dice[4][3];
int N, M;	//N = 세로 크기 M= 가로크기
int x, y;	//x 좌표 y 좌표
int K;		//K 명렬의 개수
int d_count = 0;
int flag = 1;
int cal_dice( int x, int y, int dir)
{
	int temp=0;
	d_count++;
	if ( dir == 1)	//동쪽
	{ 
		y = y + 1;
		if (y >= M || y < 0)
		{
			y -= 1;
			flag = 0;
		}
		else
		{
			flag = 1;
			temp = dice[1][2];
			dice[1][2] = dice[1][1];
			dice[1][1] = temp;

			temp = dice[1][1];
			dice[1][1] = dice[1][0];
			dice[1][0] = temp;

			temp = dice[3][1];
			dice[3][1] = dice[1][0];
			dice[1][0] = temp;
		}
	}
	
	else if ( dir == 2 )	//서쪽
	{
		y = y - 1;
		if (y < 0 || y >= M)
		{
			flag = 0;
			y += 1;
		}
		else
		{
			flag = 1;
			temp = dice[1][0];
			dice[1][0] = dice[3][1];
			dice[3][1] = temp;

			temp = dice[1][1];
			dice[1][1] = dice[1][2];
			dice[1][2] = temp;

			temp = dice[1][2];
			dice[1][2] = dice[1][0];
			dice[1][0] = temp;
		}
	}
	
	else if (dir == 3)		//북쪽
	{
		x = x - 1;
		if (x < 0 || x >= N)
		{
			flag = 0;
			x += 1;
		}
		else
		{
			flag = 1;
			temp = dice[0][1];
			dice[0][1] = dice[3][1];
			dice[3][1] = temp;

			temp = dice[0][1];
			dice[0][1] = dice[1][1];
			dice[1][1] = temp;

			temp = dice[1][1];
			dice[1][1] = dice[2][1];
			dice[2][1] = temp;
		}
	}

	else if (dir == 4)	//남쪽
	{
		x = x + 1;
		if (x < 0 || x>=N)
		{
			flag = 0;
			x = x - 1;
		}

		else
		{
			flag = 1;
			temp = dice[0][1];
			dice[0][1] = dice[3][1];
			dice[3][1] = temp;

			temp = dice[3][1];
			dice[3][1] = dice[2][1];
			dice[2][1] = temp;

			temp = dice[2][1];
			dice[2][1] = dice[1][1];
			dice[1][1] = temp;
		}
	
	}

	if (flag == 1)
	{
		if (map[x][y] == 0)
			map[x][y] = dice[3][1];

		else // map[x][y] != 0
		{
			dice[3][1] = map[x][y];
			map[x][y] = 0;
		}

		cout << dice[1][1] << endl;
	}

	while (d_count != K)
	cal_dice(x, y, direction[d_count]);

	return 0;
}

int main()
{
	cin >> N >> M >> x>> y>> K;
	memset(map, 0, sizeof(map));
	memset(direction, 0, sizeof(direction));
	memset(dice, 0, sizeof(dice));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
		cin >> direction[i];

	cal_dice(x, y, direction[0]);
	return 0;
}