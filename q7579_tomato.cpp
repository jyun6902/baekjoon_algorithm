#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int M, N, H = 0;	//M=가로 N=세로 H= 상자의 수(높이) //2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 
int maps[102][102][102];
int cnt[102][102][102];
deque <pair <int, pair<int, int>> > tomato;
int main()
{
	int result = 0;
	memset(cnt, -1, sizeof(cnt));
	cin >> M >> N >> H;

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> maps[i][j][k];	//i= 세로 j= 가로 k= 높이
				{
					if (maps[i][j][k] == 1)
					{
						cnt[i][j][k] = 0;
						tomato.push_back({ i,{j,k} });
					}
				}
			}
		}
	}

	if (tomato.size() == M*N*H)	//처음부터 다익었을 경우
	{
		cout << "0" << endl;
		return 0;
	}

	while (!tomato.empty())
	{
		int x = tomato.front().first;			//x
		int y = tomato.front().second.first;	//y
		int z = tomato.front().second.second;	//h높이
		tomato.pop_front();

		if (y + 1 < M &&  maps[x][y + 1][z] == 0 && cnt[x][y + 1][z] == -1)	//동
		{
			cnt[x][y + 1][z] = cnt[x][y][z] + 1;
			tomato.push_back({ x,{y + 1,z} });
		}

		if (y - 1 >= 0 && maps[x][y - 1][z] == 0 && cnt[x][y - 1][z] == -1)	//서
		{
			cnt[x][y - 1][z] = cnt[x][y][z] + 1;
			tomato.push_back({ x,{ y - 1,z } });
		}

		if (x - 1 >= 0 && maps[x - 1][y][z] == 0 && cnt[x - 1][y][z] == -1)	//남
		{
			cnt[x - 1][y][z] = cnt[x][y][z] + 1;
			tomato.push_back({ x - 1,{ y ,z } });
		}

		if (x + 1 < N && maps[x + 1][y][z] == 0 && cnt[x + 1][y][z] == -1)	//북
		{
			cnt[x + 1][y][z] = cnt[x][y][z] + 1;
			tomato.push_back({ x + 1,{ y ,z } });
		}

		if (z + 1 < H && maps[x][y][z + 1] == 0 && cnt[x][y][z + 1] == -1)	//상
		{
			cnt[x][y][z + 1] = cnt[x][y][z] + 1;
			tomato.push_back({ x ,{ y ,z + 1 } });
		}

		if (z - 1 >= 0 && maps[x][y][z - 1] == 0 && cnt[x][y][z - 1] == -1)	//하
		{
			cnt[x][y][z - 1] = cnt[x][y][z] + 1;
			tomato.push_back({ x ,{ y ,z - 1 } });
		}
	}

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (result < cnt[i][j][k])	//i= 세로 j= 가로 k= 높이
					result = cnt[i][j][k];
			}
		}
	}

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (cnt[i][j][k] == -1 && maps[i][j][k] == 0)	//i= 세로 j= 가로 k= 높이
					result = -1;
			}
		}
	}

	/*
		////////////////////////////////////////////////////////
		for (int k = 0; k < H; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					cout<< maps[i][j][k]<< " ";	//i= 세로 j= 가로 k= 높이

				}
				cout << endl;
			}
			cout << endl;
		}
		*/

	cout << result << endl;
	return 0;
}