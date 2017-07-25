/*
exit(0)안쓰고 return 할 경우 에러나는 문제
exit()함수는 바로 프로세스 종료.
return 은 뒤 문장을 실행하며 종료.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int maps[10][10];
bool height[10][10] = { false, };//행
bool wide[10][10] = { false, };	//열
bool square[10][10] = { false, };//사각형
#define cal(x, y) (3*(x/3)+(y/3))	//신박 node에 따라 해당값 나옴

void sdoku(int k)
{
	if (k == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << maps[i][j];
			cout << endl;
		}
		exit(0);			////return 으로 하면 error // return을 하게 될 경우 main()을 호출한 엔트리포인트코드의 뒷부분이 실행됩니다.
	}
	int x = k / 9;
	int y = k % 9;

	if (maps[x][y] != 0)
		sdoku(k + 1);

	else
	{
		for (int num = 1; num <= 9; num++)
		{
			if (!height[x][num] && !wide[y][num] && !square[cal(x, y)][num])
			{
				height[x][num] = wide[y][num] = square[cal(x, y)][num] = true;

				maps[x][y] = num;
				sdoku(k+1);

				maps[x][y] = 0;
				height[x][num] = wide[y][num] = square[cal(x, y)][num] = false;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%1d", &maps[i][j]);
			//if (maps[i][j] != 0)
				height[i][maps[i][j]] = wide[j][maps[i][j]] = square[cal(i, j)][maps[i][j]] = true;
		}
	}
	sdoku(0);
	return 0;
}