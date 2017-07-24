#include <iostream>
#include <string>
using namespace std;
string board[10];
int result = -10;
int gx, gy;
int N, M;
int cal(int b)
{
	if ((result > b || result == -10) && b <= 10)
	{
		result = b;
		return result;
	}
	return 0;
}

int maze(string board[], int rx, int ry, int bx, int by, int count, int direction)	//x=x좌표 y= y좌표, d= 방향 //1=오른쪽 2=왼쪽 3=위쪽 4= 아래쪽
{
	count++;

	if (result != -10 && result < count)
		return 0;

	if (count > 10)
		return -1;

	string board_copy[10];
	for (int i = 0; i < N; i++)
	{
		board_copy[i] = board[i];
	}

	if (direction == 1) //1=오른쪽 
	{
			if (ry > by)	//(blue, red) 순서
			{
				if (board_copy[rx][ry + 1] == '.' || board_copy[rx][ry + 1] == 'O')		//Red 이동
				{
					board_copy[rx][ry] = '.';
					while (board_copy[rx][ry + 1] == '.')
						ry++;
				}
				if (board_copy[rx][ry + 1] != 'O')
					board_copy[rx][ry] = 'R';

				//////////////////////////////////////////////////////////////
				if (board_copy[bx][by + 1] == '.')		//Blue 이동
				{
					board_copy[bx][by] = '.';
					while (board_copy[bx][by + 1] ==  '.')
						by++;
				}

				if (gx == bx && gy == by + 1)
					return 0;

				else if (gx == rx && gy == ry + 1)
					return cal( count);

				if (board_copy[bx][by + 1] != 'O')
					board_copy[bx][by] = 'B';
			}
			else //(red,blue) 순서
			{
				if (board_copy[bx][by + 1] == '.')		//Blue 이동
				{
					board_copy[bx][by] = '.';
					while (board_copy[bx][by + 1] == '.')
						by++;
				}

				if (board_copy[bx][by + 1] != 'O')
					board_copy[bx][by] = 'B';
				////////////////////////////////////////////////////////
				if (board_copy[rx][ry + 1] == '.')		//Red 이동
				{
					board_copy[rx][ry] = '.';
					while (board_copy[rx][ry + 1] == '.')
						ry++;
				}

				if (gx == bx && gy == by + 1)
					return 0;
				else if (gx == rx && gy == ry + 1)
					return  cal(count);////////////////

				if (board_copy[rx][ry + 1] != 'O')
					board_copy[rx][ry] = 'R';
			}

	}

	else if (direction == 2) //2=왼쪽
	{
			if (ry > by)	//(blue, red) 순서
			{
				if (board_copy[bx][by - 1] == '.')		//Blue 이동
				{
					board_copy[bx][by] = '.';
					while (board_copy[bx][by - 1] == '.')
						by--;

				}
				if (board_copy[bx][by - 1] != 'O')
					board_copy[bx][by] = 'B';
				//////////////////////////////////////////////////////////////
				if (board_copy[rx][ry - 1] == '.')		//Red 이동
				{
					board_copy[rx][ry] = '.';
					while (board_copy[rx][ry - 1] == '.')
						ry--;
				}

				////////////////////
				if (gx == bx && gy == by - 1)
					return 0;// 0;
				else if (gx == rx && gy == ry - 1)
					return  cal(count);
				if (board_copy[rx][ry - 1] != 'O')
					board_copy[rx][ry] = 'R';
			}

			else //(red,blue) 순서
			{

				if (board_copy[rx][ry - 1] == '.' || board_copy[rx][ry - 1] == 'O')		//Red 이동
				{
					board_copy[rx][ry] = '.';
					while (board_copy[rx][ry - 1] == '.')
						ry--;

				}
				if (board_copy[rx][ry - 1] != 'O')
					board_copy[rx][ry] = 'R';
				////////////////////////////////////////////////////////
				if (board_copy[bx][by - 1] == '.')		//Blue 이동
				{
					board_copy[bx][by] = '.';
					while (board_copy[bx][by - 1] == '.')
						by--;

				}

				//////////////////////////////////////////////////////////////
				if (gx == bx && gy == by - 1)
					return 0;
				else if (gx == rx && gy == ry - 1)
					return cal(count);////////////////

				if (board_copy[bx][by - 1] != 'O')
					board_copy[bx][by] = 'B';
			}
	}	//direction == 2

	else if (direction == 3)
	{
			if (rx > bx)	//(blue, red) 순서
			{
				if (board_copy[bx - 1][by] == '.')		//Blue 이동
				{
					board_copy[bx][by] = '.';
					while (board_copy[bx - 1][by] == '.')
						bx--;
				}

				if (board_copy[bx - 1][by] != 'O')
					board_copy[bx][by] = 'B';
				//////////////////////////////////////////////////////////////
				if (board_copy[rx - 1][ry] == '.')		//Red 이동
				{
					board_copy[rx][ry] = '.';
					while (board_copy[rx - 1][ry] == '.')
						rx--;
				}

				if (gx == bx - 1 && gy == by)
					return 0;

				else if (gx == rx - 1 && gy == ry)
					return cal(count);

				if (board_copy[rx - 1][ry] != 'O')
					board_copy[rx][ry] = 'R';
			}

			else //(red,blue) 순서
			{
				if (board_copy[rx - 1][ry] == '.' || board_copy[rx- 1][ry ] == 'O')		//Red 이동
				{
					board_copy[rx][ry] = '.';
					while (board_copy[rx - 1][ry] == '.')
						rx--;
				}

				if (board_copy[rx - 1][ry] != 'O')
					board_copy[rx][ry] = 'R';
				////////////////////////////////////////////////////////
				if (board_copy[bx - 1][by] == '.')		//Blue 이동
				{
					board_copy[bx][by] = '.';
					while (board_copy[bx - 1][by] == '.')
						bx--;
				}

				if (gx == bx - 1 && gy == by)
					return 0;
				else if (gx == rx - 1 && gy == ry)
					return cal( count);


				if (board_copy[bx - 1][by] != 'O')
					board_copy[bx][by] = 'B';
			}
	}//direction == 3

	else if (direction == 4)	//아래쪽
	{
			if (rx > bx)	//(blue, red) 순서
			{
				if (board_copy[rx + 1][ry] == '.' || board_copy[rx+ 1][ry ] == 'O')		//Red 이동
				{
					board_copy[rx][ry] = '.';
					while (board_copy[rx + 1][ry] == '.')
						rx++;
				}

				if (board_copy[rx + 1][ry] != 'O')
					board_copy[rx][ry] = 'R';
				//////////////////////////////////////////////////////////////
				if (board_copy[bx + 1][by] == '.')		//Blue 이동
				{
					board_copy[bx][by] = '.';
					while (board_copy[bx + 1][by] == '.')
						bx++;
				}

				if (gx == bx + 1 && by == gy)
					return 0;

				else if (gx == rx + 1 && gy == ry)
					return cal( count);

				if (board_copy[bx + 1][by] != 'O')
					board_copy[bx][by] = 'B';
			}

			else //(red,blue) 순서
			{
				if (board_copy[bx + 1][by] == '.')		//Blue 이동
				{
					board_copy[bx][by] = '.';
					while (board_copy[bx + 1][by] == '.')
						bx++;
				}

				if (board_copy[bx + 1][by] != 'O')
					board_copy[bx][by] = 'B';
				////////////////////////////////////////////////////////
				if (board_copy[rx + 1][ry] == '.')		//Red 이동
				{
					board_copy[rx][ry] = '.';
					while (board_copy[rx + 1][ry] == '.')
						rx++;
				}
				if (gx == bx + 1 && gy == by)
					return 0;

				else if (gx == rx + 1 && gy == ry)
					return  cal( count);

				if (board_copy[rx + 1][ry] != 'O')
					board_copy[rx][ry] = 'R';
			}

	}	//direction == 4

		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << board_copy[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		

	if (board_copy[bx][by + 1] != '#' || board_copy[rx][ry + 1] != '#')
		maze(board_copy, rx, ry, bx, by, count, 1);	//(result[], rx, ry, bx, by, count, direction)	//a=x좌표 b= y좌표, c= 방향 //1=오른쪽 2=왼쪽 3=위쪽 4= 아래쪽

	if (board_copy[bx][by - 1] != '#' || board_copy[rx][ry - 1] != '#')
		maze(board_copy, rx, ry, bx, by, count, 2);

	if (board_copy[bx - 1][by] != '#' || board_copy[rx - 1][ry] != '#')
		maze(board_copy, rx, ry, bx, by, count, 3);

	if (board_copy[bx + 1][by] != '#' || board_copy[rx + 1][ry] != '#')
		maze(board_copy, rx, ry, bx, by, count, 4);

}

int main()
{

	int rx = 0, ry = 0, bx = 0, by = 0;
	cin >> N >> M;
	gx = 0, gy = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'R')
			{
				rx = i;
				ry = j;
			}
			if (board[i][j] == 'B')
			{
				bx = i;
				by = j;
			}

			if (board[i][j] == 'O')
			{
				gx = i;
				gy = j;
			}
		}
	}

	maze(board, rx, ry, bx, by, 0, 1);	//(result[], rx, ry, bx, by, count, direction)	//a=x좌표 b= y좌표, c= 방향 //1=오른쪽 2=왼쪽 3=위쪽 4= 아래쪽
	maze(board, rx, ry, bx, by, 0, 2);
	maze(board, rx, ry, bx, by, 0, 3);
	maze(board, rx, ry, bx, by, 0, 4);

	if (result == -10)
		result = -1;

	cout << result;
	return 0;
}
