#include <iostream>
#include <cstring>
using namespace std;
int N, M = 0;
int maze[103][103];
int result = 987654;

void go(int board[][103], bool visit[][103], int x, int y, int cnt)
{
	if (x == N && y == M && (result > cnt))
		result = cnt;

	if (cnt > result)
	{
		visit[x][y] = true;
		return;
	}
	if (y < M && visit[x][y + 1] == false)		//동
	{
		visit[x][y + 1] = true;
		if (board[x][y + 1] == 1)
			go(board, visit, x, y + 1, cnt + 1);

		else
			go(board, visit, x, y + 1, cnt);

	visit[x][y + 1] = false;
	}

	if (y > 1 && visit[x][y - 1] == false)		//서
	{
		visit[x][y - 1] = true;
		if (board[x][y - 1] == 1)
			go(board, visit, x, y - 1, cnt + 1);

		else
			go(board, visit, x, y - 1, cnt);

		visit[x][y - 1] = false;
	}

	if (x < N && visit[x + 1][y] == false)		//남
	{
		visit[x + 1][y] = true;
		if (board[x + 1][y] == 1)
			go(board, visit, x + 1, y, cnt + 1);

		else
			go(board, visit, x + 1, y, cnt);

		visit[x + 1][y] = false;
	}


	if (x > 1 && visit[x - 1][y] == false)		//북
	{
		visit[x - 1][y] = true;
		if (board[x - 1][y] == 1)
			go(board, visit, x - 1, y, cnt + 1);

		else
			go(board, visit, x - 1, y, cnt);

		visit[x - 1][y] = false;
	}
}

int main()
{
	cin >> M >> N;	//M= 가로 N= 세로 
	memset(maze, -1, sizeof(maze));
	bool visit[103][103] = { false, };

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			scanf("%1d", &maze[i][j]);
	}
	visit[1][1] = true;
	go(maze, visit, 1, 1, 0);
	cout << result;
	return 0;
}