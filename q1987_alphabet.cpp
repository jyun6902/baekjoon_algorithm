#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int R, C = 0;
int ans = 1;

void go(char board[][22], bool check[], int x, int y, int cnt)
{
	if (ans < cnt)
		ans = cnt;

	if (y < C && check[board[x][y + 1] - 'A'] == false)		//동
	{
		check[board[x][y + 1] - 'A'] = true;
		go(board, check, x, y + 1, cnt + 1);
		check[board[x][y + 1] - 'A'] = false;
	}

	if (y > 1 && check[board[x][y - 1] - 'A'] == false)		//서
	{
		check[board[x][y - 1] - 'A'] = true;
		go(board, check, x, y - 1, cnt + 1);
		check[board[x][y - 1] - 'A'] = false;
	}


	if (x < R && check[board[x + 1][y] - 'A'] == false)		//남
	{
		check[board[x + 1][y] - 'A'] = true;
		go(board, check, x + 1, y, cnt + 1);
		check[board[x + 1][y] - 'A'] = false;
	}

	if (x > 1 && check[board[x - 1][y] - 'A'] == false)		//북
	{
		check[board[x - 1][y] - 'A'] = true;
		go(board, check, x - 1, y, cnt + 1);
		check[board[x - 1][y] - 'A'] = false;
	}
}

int main()
{
	cin >> R >> C;
	char arr[22][22];
	bool check[28] = { false, };
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			scanf("%1s", &arr[i][j]);
		}
	}
	check[arr[1][1] - 'A'] = true;	//아스키코드로 빼기
	go(arr, check, 1, 1, 1);
	cout << ans;
	return 0;
}