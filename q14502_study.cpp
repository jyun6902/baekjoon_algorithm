#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
//0 빈칸 1 벽 2 바이러스
int N, M;	//N ;세로 크기 M 가로 크기
int map[10][10];
int map_copy[10][10];
deque <pair<int, int>> virus;
deque <pair<int, int>> virus_copy;
int main()
{
	
	cin >> N >> M;
	int first_x, first_y, second_x, second_y, third_x, third_y;
	int zero_count = 0;
	int result = 0;
	memset(map, 0, sizeof(map));
	memset(map_copy, -1, sizeof(map_copy));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map_copy[i][j];
			map[i][j] = map_copy[i][j];

			if (map[i][j] == 2)
				virus_copy.push_back({ i,j });
		}
	}

	for (int i1 = 1; i1 <= N; i1++)
	{
		for (int j1 = 1; j1 <= M; j1++)
		{
			if (map[i1][j1] != 0)
				continue;

			for (int i2 = 1; i2 <= N; i2++)
			{
				for (int j2 = 1; j2 <= M; j2++)
				{
					if (map[i2][j2] != 0 || (i1 == i2 && j1 == j2))
						continue;

					for (int i3 = 1; i3 <= N; i3++)
					{
						for (int j3 = 1; j3 <= M; j3++)
						{
							if (map[i3][j3] != 0 || (i1 == i3 && j1 == j3) || (i2 == i3 && j2 == j3))
								continue;

							else
							{
								first_x = i1;
								first_y = j1;

								second_x = i2;
								second_y = j2;

								third_x = i3;
								third_y = j3;
							}	//else

							map[first_x][first_y] = 3;
							map[second_x][second_y] = 3;
							map[third_x][third_y] = 3;

							virus = virus_copy;
							while (!virus.empty())
							{
								int x = virus.back().first;
								int y = virus.back().second;

								virus.pop_back();
								map[x][y] = 2;

								if (y < 0 || y> M || x < 0 || x>N)
									continue;

								else
								{
									if (map[x][y + 1] == 0)	//동
										virus.push_back({ x, y + 1 });

									if (map[x][y - 1] == 0)	//서
										virus.push_back({ x, y - 1 });

									if (map[x + 1][y] == 0)	//남
										virus.push_back({ x + 1, y });

									if (map[x - 1][y] == 0)	//북
										virus.push_back({ x - 1, y });

								}	//else
							}

							zero_count = 0;
							for (int i = 1; i <= N; i++)
							{
								for (int j = 1; j <= M; j++)
								{
									if (map[i][j] == 0 )
										zero_count++;
								}
							}

							if (result < zero_count)
								result = zero_count;

							for (int i = 1; i <= N; i++)
							{
								for (int j = 1; j <= M; j++)
								{
									map[i][j] = map_copy[i][j];

								}
							}
						}	//for j3
					}		//for i3
				}			//for j2 
			}				//for i2
		}					//for j1
	}						//for i1

	cout << result << endl;
	return 0;
}