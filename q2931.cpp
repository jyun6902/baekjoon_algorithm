#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
/*
'|'(아스키 124), '-', '+',
'1 :┌', '2 : └', '3 : ┘', '4 : ┐'
x, y좌표 헷갈리지 않기!! x; 세로 y; 가로로 놓음
*/
int R, C;	//R=세로 C=가로 
char europe[28][28] = { 0 };
int visit[28][28], connect[28][28];	//connect= 연결되어있는지 여부
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int empty_x = 0, empty_y = 0;
char shape[1];
deque <pair<int, int >> step;

void result_shape(int x, int y)//빈칸 모양 판별
{
	if (europe[x][y - 1] == '-' || europe[x][y - 1] == '+' || europe[x][y - 1] == '1' || europe[x][y - 1] == '2')
		connect[x][y - 1] = 1;	//연결되어있을 경우 (서)
	else
		connect[x][y - 1] = 2;

	if (europe[x][y + 1] == '-' || europe[x][y + 1] == '+' || europe[x][y + 1] == '3' || europe[x][y + 1] == '4')
		connect[x][y + 1] = 1;	//연결되어있을 경우 (동)
	else
		connect[x][y + 1] = 2;

	if (europe[x - 1][y] == '|' || europe[x - 1][y] == '+' || europe[x - 1][y] == '1' || europe[x - 1][y] == '4')
		connect[x - 1][y] = 1;	//연결되어있을 경우 (북)
	else
		connect[x - 1][y] = 2;

	if (europe[x + 1][y] == '|' || europe[x + 1][y] == '+' || europe[x + 1][y] == '2' || europe[x + 1][y] == '3')
		connect[x + 1][y] = 1;	//연결되어있을 경우 (남)
	else
		connect[x + 1][y] = 2;

	if (connect[x][y - 1] == 2 && connect[x][y + 1] == 2 && connect[x + 1][y] == 1 && connect[x - 1][y] == 1)
		shape[0] = '|';

	else if (connect[x][y - 1] == 1 && connect[x][y + 1] == 1 && connect[x + 1][y] == 2 && connect[x - 1][y] == 2)
		shape[0] = '-';

	else if (connect[x][y - 1] == 1 && connect[x][y + 1] == 1 && connect[x + 1][y] == 1 && connect[x - 1][y] == 1)
		shape[0] = '+';

	else if (connect[x][y - 1] == 2 && connect[x][y + 1] == 1 && connect[x + 1][y] == 1 && connect[x - 1][y] == 2)
		shape[0] = '1';	//┌

	else if (connect[x][y - 1] == 2 && connect[x][y + 1] == 1 && connect[x + 1][y] == 2 && connect[x - 1][y] == 1)
		shape[0] = '2';	//└

	else if (connect[x][y - 1] == 1 && connect[x][y + 1] == 2 && connect[x + 1][y] == 2 && connect[x - 1][y] == 1)
		shape[0] = '3';	//┘

	else if (connect[x][y - 1] == 1 && connect[x][y + 1] == 2 && connect[x + 1][y] == 1 && connect[x - 1][y] == 2)
		shape[0] = '4';	//┐
}

int check(int x, int y)
{
	if (x < 1 || x > R || y < 1 || y > C)	//x= 세로 y= 가로
		return 0;
	else
		return 1;
}

void dfs(int x, int y)
{
	visit[x][y] = 1;
	int nx = x, ny = y;
	if (europe[x][y] == '|')
	{
		nx = x + 1;
		ny = y;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);

		nx = x - 1;
		ny = y;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);
	}

	else if (europe[x][y] == '-')
	{
		nx = x;
		ny = y - 1;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);

		nx = x;
		ny = y + 1;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);
	}

	else if (europe[x][y] == '+')
	{
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (check(nx, ny) == 1 && visit[nx][ny] == 0)
				dfs(nx, ny);
		}
	}

	else if (europe[x][y] == '1')		//┌
	{
		nx = x + 1;
		ny = y;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);

		nx = x;
		ny = y + 1;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);
	}

	else if (europe[x][y] == '2')		//└
	{
		nx = x;
		ny = y + 1;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);

		nx = x - 1;
		ny = y;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);
	}

	else if (europe[x][y] == '3')		//┘
	{
		nx = x;
		ny = y - 1;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);

		nx = x - 1;
		ny = y;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);
	}

	else if (europe[x][y] == '4')		//┐
	{
		nx = x;
		ny = y - 1;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);

		nx = x + 1;
		ny = y;
		if (check(nx, ny) == 1 && visit[nx][ny] == 0)
			dfs(nx, ny);
	}

	else if (europe[x][y] == '.')		//빈공간
	{
		empty_x = x;
		empty_y = y;
		result_shape(empty_x, empty_y);
	}
}



int main()
{
	cin >> R >> C;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> europe[i][j];
			if (europe[i][j] == 'M')	//출발점
				step.push_back({ i,j });
		}
	}

	int x = step.front().first;
	int y = step.front().second;
	int cnt = 0;
	step.pop_front();

	for (int i = 0; i < 4; i++)
	{
		int n_x = x + dx[i];
		int n_y = y + dy[i];

		if (n_x < 1 || n_x > R || n_y < 1 || n_y > C)
			continue;

		if (europe[n_x][n_y] != '.')
			dfs(n_x, n_y);
	}

	cout << empty_x << " " << empty_y << " " << shape[0] << endl;
	return 0;
}