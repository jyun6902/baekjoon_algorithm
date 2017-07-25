#include <iostream>
#include <deque>
#include <cstdlib>
using namespace std;
int maps[10][10];
bool height[10][10] = { false, };//행
bool wide[10][10] = { false, };	//열
bool square[10][10] = { false, };//사각형
deque <pair<int, int>> zero;

#define cal(x, y) (3*(x/3)+(y/3))	//신박 node에 따라 해당값 나옴

void sdoku(int k)
{
	if (k == 81 )
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << maps[i][j] << " ";
			cout << endl;
		}
		return; 
	}
	int x = k / 9;
	int y = k % 9;

	if (maps[x][y] != 0)
		sdoku(k+ 1);

	else
	{
		for (int num = 1; num <= 9; num++)
		{
			if (!height[x][num] && !wide[y][num] && !square[cal(x, y)][num])
			{
				height[x][num] = true;
				wide[y][num] = true;
				square[cal(x, y)][num] = true;

				maps[x][y] = num;
				sdoku(k + 1);

				maps[x][y] = 0;
				height[x][num] = false;
				wide[y][num] = false;
				square[cal(x, y)][num] = false;
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
			cin >> maps[i][j];

			if (maps[i][j] != 0)		//0일 경우 zero queue에 넣기
			{
				height[i][maps[i][j]] = true;
				wide[j][maps[i][j]] = true;
				square[cal(i, j)][maps[i][j]] = true;
			}
		}
	}
	sdoku(0);
	return 0;
}