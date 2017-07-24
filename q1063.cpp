/*
if 문에 안들어가는 경우는 pop되면 안됨
->pop if문 안에서 하도록!
*/
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
int maps[10][10];
int N;
queue <pair<int, int>> king;
queue <pair<int, int>> stone;
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };//동, 서, 남, 북,
int dy[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int main()
{
	memset(maps, 0, sizeof(maps));
	string king_dir, stone_dir;
	string order;
	cin >> king_dir >> stone_dir >> N;//킹위치, 돌위치, 움직이는 횟수

	int w = king_dir[0] - 64;
	int h = king_dir[1] - 48;
	maps[h][w] = 1;	//king
	king.push({ h,w });

	w = stone_dir[0] - 64;	//알파벳
	h = stone_dir[1] - 48;
	maps[h][w] = 2;	//stone
	stone.push({ h,w });

	for (int i = 1; i <= N; i++)
	{
		cin >> order;

		int x = king.front().first;
		int y = king.front().second;

		int stone_x = stone.front().first;
		int stone_y = stone.front().second;

		if (order == "R")	//오른쪽
		{
			if (y + 1 <= 8 && maps[x][y + 1] == 0)
			{
				maps[x][y] = 0;
				maps[x][y + 1] = 1;

				king.pop();
				king.push({ x,y + 1 });
			}

			else if (y + 2 <= 8 && maps[x][y + 1] != 0)
			{
				maps[x][y + 2] = 2;
				maps[x][y + 1] = 1;
				maps[x][y] = 0;

				king.pop();
				king.push({ x,y + 1 });
				stone.pop();
				stone.push({ x,y + 2 });
			}
		}

		else if (order == "L")	//왼쪽
		{
			if (y - 1 > 0 && maps[x][y - 1] == 0)
			{
				maps[x][y] = 0;
				maps[x][y - 1] = 1;

				king.pop();
				king.push({ x,y - 1 });
			}

			else if (y - 2 > 0 && maps[x][y - 1] != 0)
			{
				maps[x][y - 2] = 2;
				maps[x][y - 1] = 1;
				maps[x][y] = 0;

				king.pop();
				king.push({ x,y - 1 });
				stone.pop();
				stone.push({ x,y - 2 });
			}
		}

		else if (order == "B")	//남
		{
			if (x - 1 > 0 && maps[x - 1][y] == 0)
			{
				maps[x][y] = 0;
				maps[x - 1][y] = 1;

				king.pop();
				king.push({ x - 1,y });
			}

			else if (x - 2 > 0 && maps[x - 1][y] != 0)
			{
				maps[x - 2][y] = 2;
				maps[x - 1][y] = 1;
				maps[x][y] = 0;

				king.pop();
				king.push({ x - 1,y });
				stone.pop();
				stone.push({ x - 2, y });
			}
		}

		else if (order == "T")	//북
		{
			if (x + 1 <= 8 && maps[x + 1][y] == 0)
			{
				maps[x][y] = 0;
				maps[x + 1][y] = 1;

				king.pop();
				king.push({ x + 1,y });
			}

			else if (x + 2 <= 8 && maps[x + 1][y] != 0)
			{
				maps[x + 2][y] = 2;
				maps[x + 1][y] = 1;
				maps[x][y] = 0;

				king.pop();
				king.push({ x + 1,y });
				stone.pop();
				stone.push({ x + 2, y });
			}
		}

		else if (order == "RT")	//오른쪽대각선 위
		{
			if (x + 1 <= 8 && y + 1 <= 8 && maps[x + 1][y + 1] == 0)
			{
				maps[x][y] = 0;
				maps[x + 1][y + 1] = 1;

				king.pop();
				king.push({ x + 1,y + 1 });
			}

			else if (x + 2 <= 8 && y + 2 <= 8 && maps[x + 1][y + 1] != 0)
			{
				maps[x + 2][y + 2] = 2;
				maps[x + 1][y + 1] = 1;
				maps[x][y] = 0;

				king.pop();
				king.push({ x + 1,y + 1 });
				stone.pop();
				stone.push({ x + 2, y + 2 });
			}
		}

		else if (order == "LT")	//왼쪽대각선 위
		{
			if (x + 1 <= 8 && y - 1 > 0 && maps[x + 1][y - 1] == 0)
			{
				maps[x][y] = 0;
				maps[x + 1][y - 1] = 1;

				king.pop();
				king.push({ x + 1,y - 1 });
			}

			else if (x + 2 <= 8 && y - 2 > 0 && maps[x + 1][y - 1] != 0)
			{
				maps[x + 2][y - 2] = 2;
				maps[x + 1][y - 1] = 1;
				maps[x][y] = 0;

				king.pop();
				king.push({ x + 1,y - 1 });
				stone.pop();
				stone.push({ x + 2, y - 2 });
			}
		}

		else if (order == "RB")	//오른쪽 아래 대각선
		{
			if (x - 1 > 0 && y + 1 <= 8 && maps[x - 1][y + 1] == 0)
			{
				maps[x][y] = 0;
				maps[x - 1][y + 1] = 1;

				king.pop();
				king.push({ x - 1,y + 1 });
			}

			else if (x - 2 > 0 && y + 2 <= 8 && maps[x - 1][y + 1] != 0)
			{
				maps[x - 2][y + 2] = 2;
				maps[x - 1][y + 1] = 1;
				maps[x][y] = 0;

				king.pop();
				king.push({ x - 1,y + 1 });
				stone.pop();
				stone.push({ x - 2, y + 2 });
			}
		}

		else if (order == "LB")	//왼쪽 아래 대각선
		{
			if (x - 1 > 0 && y - 1 > 0 && maps[x - 1][y - 1] == 0)
			{
				maps[x][y] = 0;
				maps[x - 1][y - 1] = 1;

				king.pop();
				king.push({ x - 1,y - 1 });
			}

			else if (x - 2 > 0 && y - 2 > 0 && maps[x - 1][y - 1] != 0)
			{
				maps[x - 2][y - 2] = 2;
				maps[x - 1][y - 1] = 1;
				maps[x][y] = 0;

				king.pop();
				king.push({ x - 1,y - 1 });
				stone.pop();
				stone.push({ x - 2, y - 2 });
			}
		}

	}	//for i

	cout << char(king.front().second + 64) << king.front().first << endl;
	cout << char(stone.front().second + 64) << stone.front().first << endl;
	return 0;
}