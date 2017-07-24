#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

int N, M;
int cheese[102][102];
deque<pair<int, int>> check;
int main()
{
	int time_result = 0;
	int two_count = 0;
	int x = 1, y = 1;
	cin >> N >> M;
	memset(cheese, -1, sizeof(cheese));


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> cheese[i][j];
		}
	}

	cheese[1][1] = 2;
	check.push_back({ 1,1 });
	while (!check.empty())
	{
		x = check.back().first;
		y = check.back().second;
		check.pop_back();
		cheese[x][y] = 2;

		if (y < 0 || y>M || x < 0 || x>N)
		{
			continue;
		}
		else
		{
			if (cheese[x][y + 1] == 0)
				check.push_back({ x, y + 1 });

			if (cheese[x + 1][y] == 0)
				check.push_back({ x + 1 , y });

			if (cheese[x - 1][y] == 0)
				check.push_back({ x - 1, y });

			if (cheese[x][y - 1] == 0)
				check.push_back({ x, y - 1 });
		}


	}

	while (1)
	{
		time_result++;
	
		for (int i = 1; i <= N; i++)		// 확인
		{
			for (int j = 1; j <= M; j++)
			{
				int c_count = 0;
				if (cheese[i][j] == 1)
				{
					if (cheese[i][j + 1] == 2)
					{
						c_count++;
					}

					if (cheese[i + 1][j] == 2)
					{
						c_count++;
					}

					if (cheese[i - 1][j] == 2)
					{
						c_count++;
					}

					if (cheese[i][j - 1] == 2)
					{
						c_count++;
					}
				}
				if (c_count >= 2)
					cheese[i][j] = 3;
			}
		}

		for (int i = 1; i <= N; i++)		// 확인
		{
			for (int j = 1; j <= M; j++)
			{
				if (cheese[i][j] == 3)
				{
					cheese[i][j] = 2;
					check.push_back({ i,j });
					while (!check.empty())
					{
						x = check.back().first;
						y = check.back().second;
						check.pop_back();
						cheese[x][y] = 2;

						if (y < 0 || y>M || x < 0 || x>N)
						{

							continue;
						}
						else
						{
							if (cheese[x][y + 1] == 0)
								check.push_back({ x, y + 1 });

							if (cheese[x + 1][y] == 0)
								check.push_back({ x + 1 , y });

							if (cheese[x - 1][y] == 0)
								check.push_back({ x - 1, y });

							if (cheese[x][y - 1] == 0)
								check.push_back({ x, y - 1 });
						}


					}
				}
			}
		}


		two_count = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (cheese[i][j] == 2)
					two_count++;
			}
		}
		if (two_count == N*M)
			break;

	}



	cout << time_result << endl;
	return 0;
}