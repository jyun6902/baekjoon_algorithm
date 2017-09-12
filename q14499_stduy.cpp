/*
 N,M 범위 넘어가는 경우, 재귀함수에서 계속 반복될 수 있음
 ->flag로 조건 주어 반복없앰
*/
#include <iostream>
#include <cstring>
using namespace std;
int N, M, x, y, K = 0;//N=세로, M=가로, x, y=주사위 좌표, K= 명령의 개수
int maps[22][22];
int order[1001];
int flag = 0;			//범위 벗어날때 재귀함수라 계속 반복해서 조건 걸어줌
int dice[4][3] = { { 0, 0, 0 }
				, { 0, 0, 0 }
				, { 0, 0, 0 }
				, { 0, 0, 0 } };

void swap_dice(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void dice_cal(int a, int b, int dir, int cnt)
{
	if (cnt > K)
	{
		flag = 1;
		return;
	}

	if (dir == 1)//동
	{
		if (b + 1 >= M&& flag == 0)
			dice_cal(a, b, order[cnt + 1], cnt + 1);
		else
		{
			swap_dice(&dice[1][0], &dice[3][1]);
			swap_dice(&dice[1][1], &dice[1][2]);
			swap_dice(&dice[1][1], &dice[3][1]);
			b += 1;
		}
	}

	else if (dir == 2)//서
	{
		if (b - 1 < 0 && flag == 0)
			dice_cal(a, b, order[cnt + 1], cnt + 1);
		else
		{
			swap_dice(&dice[1][2], &dice[3][1]);
			swap_dice(&dice[1][0], &dice[3][1]);
			swap_dice(&dice[1][0], &dice[1][1]);
			b -= 1;
		}
	}

	else if (dir == 3)//북
	{
		if (a - 1 < 0 && flag == 0)
			dice_cal(a, b, order[cnt + 1], cnt + 1);
		else
		{
			swap_dice(&dice[0][1], &dice[1][1]);
			swap_dice(&dice[1][1], &dice[2][1]);
			swap_dice(&dice[2][1], &dice[3][1]);
			a -= 1;
		}
	}

	else if (dir == 4)//남
	{
		if (a + 1 >= N&& flag == 0)
			dice_cal(a, b, order[cnt + 1], cnt + 1);
		else
		{
			swap_dice(&dice[0][1], &dice[1][1]);
			swap_dice(&dice[2][1], &dice[3][1]);
			swap_dice(&dice[0][1], &dice[2][1]);
			a += 1;
		}

	}

	if (maps[a][b] == 0 && flag == 0)		//지도가 0일 경우
	{
		maps[a][b] = dice[3][1];//주사위 밑면 지도에 복사
		cout << dice[1][1] << endl;			//윗면 출력
	}

	else if (maps[a][b] > 0 && flag == 0)	//지도가 0이 아닐 경우
	{
		dice[3][1] = maps[a][b];//지도 밑면 주사위에 복사
		maps[a][b] = 0;			//지도 0
		cout << dice[1][1] << endl;
	}

	if (flag == 0)
		dice_cal(a, b, order[cnt + 1], cnt + 1);
	else
		return;
}

int main()
{
	memset(maps, -1, sizeof(maps));
	int dir = 4;
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> maps[i][j];
	}

	for (int i = 1; i <= K; i++)
		cin >> order[i];

	dice_cal(x, y, order[1], 1);	//dice_cal(int a, int b, int dir, int cnt)

	return 0;
}