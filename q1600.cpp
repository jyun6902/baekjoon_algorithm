#include <iostream>
#include <deque>
using namespace std;

int K = 0, W = 0, H = 0;	//K= 체스처럼 움직일 수 있는 수 W=가로 H=세로
int dx[12] = { 0, 0, 1, -1, 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[12] = { 1, -1, 0, 0, 2, 1, -1, -2, -2, -1, 1, 2 };
bool visit[201][201][31] = { 0 };
int maps[201][201];
int step = 0;
int main()
{
	deque < pair<pair<int, int>, int>> monkey;	//x, y, K=cnt
	cin >> K >> W >> H;	// 0<= K <=30 //1<=W,H<=20
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cin >> maps[i][j];
	}

	monkey.push_back({ { 1,1 }, 0 });

	while (!monkey.empty())
	{
		int t = monkey.size();
		while (t--)
		{
			int x = monkey.front().first.first;
			int y = monkey.front().first.second;
			int cnt = monkey.front().second;	//K
			monkey.pop_front();

			if (visit[x][y][cnt] == 1)
				continue;
			else
				visit[x][y][cnt] = 1;

			if (x == H && y == W)
			{
				cout << step << endl;
				return 0;
			}

			for (int i = 0; i < 12; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 1 || nx > H || ny < 1 || ny > W || maps[nx][ny] == 1)
					continue;

				if (i < 4 && visit[nx][ny][cnt] == 0)
					monkey.push_back({ { nx, ny },  cnt });

				else if (cnt < K && visit[nx][ny][cnt] == 0)
					monkey.push_back({ { nx, ny },  cnt + 1 });
			}
		}
		step++;
	}//while

	cout << "-1" << endl;
	return 0;
}