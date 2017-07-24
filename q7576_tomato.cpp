#include <iostream>
#include <cstring>
#include <deque>

using namespace std;
int M, N = 0;//M=가로, N=세로
int maps[1002][1002];
int cnt[1002][1002];
deque <pair<int, int>> tomato;
int main()
{
	int result = 0;
	memset(cnt, -1, sizeof(cnt));
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 1 )
			{
				cnt[i][j] = 0;
				tomato.push_back({ i,j });
			}
		}
	}

	if (tomato.size() == M*N) ////저장될 때 부터 다익었을 경우
	{
		cout << "0" << endl;
		return 0;
	}
	while (!tomato.empty())
	{
		int x = tomato.front().first;
		int y = tomato.front().second;
		tomato.pop_front();
		if (y + 1 < M && maps[x][y + 1] == 0 && cnt[x][y + 1] == -1)	//동
		{
			cnt[x][y + 1] = cnt[x][y] + 1;
			tomato.push_back({ x,y + 1 });
		}
		if (y - 1 >= 0 && maps[x][y - 1] == 0 && cnt[x][y - 1] == -1)	//서
		{
			cnt[x][y - 1] = cnt[x][y] + 1;
			tomato.push_back({ x,y - 1 });
		}
		if (x + 1 < N && maps[x + 1][y] == 0 && cnt[x + 1][y] == -1)	//남
		{
			cnt[x + 1][y] = cnt[x][y] + 1;
			tomato.push_back({ x + 1,y });
		}
		if (x - 1 >= 0 && maps[x - 1][y] == 0 && cnt[x - 1][y] == -1)	//북
		{
			cnt[x - 1][y] = cnt[x][y] + 1;
			tomato.push_back({ x - 1,y });
		}
	}	//while

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (result < cnt[i][j])
				result = cnt[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (cnt[i][j] == -1 && maps[i][j] == 0)	//다 못익음
			{
				result = -1;
			}
		}
	}

	cout << result << endl;
	return 0;
}