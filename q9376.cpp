#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

char maps[105][105] = {};
int helper[105][105] = {};
int person1[105][105] = {};
int person2[105][105] = {};
int dx[4] = { 0, 0 ,1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int h, w = 0;//h= 높이 w= 너비
/*
BFS할때 최솟값으로 업데이트 하기
*/
void bfs(int(*arr)[105], int x, int y)
{
	deque <pair<int, int>> dq;
	
	memset(arr, 0, sizeof(arr));
	dq.push_back( {x, y});
	fill(&arr[0][0], &arr[104][104] + 1, 987654321);
	int n_x = 0, n_y = 0;
	
	arr[x][y] = 0;
	while (!dq.empty())
	{
		int dq_s = dq.size();
		for (int dq_size = 0; dq_size < dq_s; dq_size++)
		{
			int xx = dq.front().first;
			int yy = dq.front().second;
			dq.pop_front();
			for (int i = 0; i < 4; i++)
			{
				n_x = xx + dx[i];
				n_y = yy + dy[i];

				if (n_x <0 || n_x > h + 1 || n_y < 0 || n_y > w + 1 || maps[n_x][n_y] == '*' )
					continue;

				if ( maps[n_x][n_y] == '.' || maps[n_x][n_y] == '$')
				{
					if (arr[n_x][n_y] <= arr[xx][yy])
						continue;

						dq.push_back( {n_x, n_y});
						arr[n_x][n_y] = arr[xx][yy];
				}
				else if ( maps[n_x][n_y] == '#')
				{
					if (arr[n_x][n_y] <= arr[xx][yy] +1)
						continue;
		
						dq.push_back({n_x, n_y});
						arr[n_x][n_y] = arr[xx][yy] + 1;
				}
			}
		}
	}
}

int main()
{
	int test_case = 0;
	cin >> test_case;
	for (int test_cnt = 1; test_cnt <= test_case; test_cnt++)
	{
		memset(helper, 0, sizeof(helper));
		memset(person1, 0, sizeof(person1));
		memset(person2, 0, sizeof(person2));
		memset(maps, 0, sizeof(maps));
		deque <pair<int, int>> dq;
		int result = 987654321;
		cin >> h >> w;

		for (int i = 0; i <= h+1; i++)
		{
			for (int j = 0; j <= w+1; j++)
			{
				if (i == 0 || i == h + 1 || j == 0 || j == w + 1)
					maps[i][j] = '.';
				else
				{
					cin >> maps[i][j];
					if (maps[i][j] == '$')
						dq.push_back({ i,j });
				}
			}
		}

		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();
		bfs(person1, x, y);

		x = dq.front().first;
		y = dq.front().second;
		dq.pop_front();

		bfs(person2, x, y);
		bfs(helper, 0, 0);//helper
		
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				x = helper[i][j] + person1[i][j] + person2[i][j];
				if (maps[i][j] == '#')
					x -= 2;
				if ((result > x) && (maps[i][j] != '*'))
					result = x;
			}
		}
		cout << result << endl;
	}
	return 0;
}