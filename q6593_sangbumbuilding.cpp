#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int main()
{
	char building[33][33][33];
	int visit[33][33][33];
	deque <pair <int, pair<int, int >> > person;

	while (1)
	{
		int L, R, C = 0;
		int flag = 0;
		int end_x = 0, end_y = 0, end_z = 0;

		cin >> L >> R >> C; 	//L=상범빌딩 층수, R=행 C=열
		if (L == 0 && R == 0 && C == 0)
			return 0;
		else
		{
			memset(visit, -1, sizeof(visit));
			memset(building,0, sizeof(building));
			
			for (int k = 0; k < L; k++)
			{
				for (int i = 0; i < R; i++)
				{
					for (int j = 0; j < C; j++)
					{
						cin >> building[i][j][k];
						if (building[i][j][k] == 'S')
						{
							visit[i][j][k] = 0;
							person.push_back({ i,{j,k} });
						}
						if (building[i][j][k] == 'E')
						{
							end_x = i;
							end_y = j;
							end_z = k;
						}
					}// for j
				}//for  i
			}//for k
		}


		while (!person.empty())
		{
			int x = person.front().first;			// 행
			int y = person.front().second.first;	//열
			int z = person.front().second.second;	//높이
			person.pop_front();

			if (y + 1 < C && (building[x][y + 1][z] == '.' || building[x][y + 1][z] == 'E') && visit[x][y + 1][z] == -1)	//동
			{
				visit[x][y + 1][z] = visit[x][y][z] + 1;
				if (building[x][y + 1][z] == 'E')
				{
					flag = 1;
					break;
				}
				person.push_back({ x, {y + 1,z} });
			}

			if (y - 1 >= 0 && (building[x][y - 1][z] == '.' || building[x][y - 1][z] == 'E') && visit[x][y - 1][z] == -1)		//서
			{
				visit[x][y - 1][z] = visit[x][y][z] + 1;
				if (building[x][y - 1][z] == 'E')
				{
					flag = 1;
					break;
				}
				person.push_back({ x,{ y - 1,z } });
			}

			if (x + 1 < R && (building[x + 1][y][z] == '.' || building[x + 1][y][z] == 'E') && visit[x + 1][y][z] == -1)	//남
			{
				visit[x + 1][y][z] = visit[x][y][z] + 1;
				if (building[x + 1][y][z] == 'E')
				{
					flag = 1;
					break;
				}
				person.push_back({ x + 1,{ y,z } });
			}


			if (x - 1 >= 0 && (building[x - 1][y][z] == '.' || building[x - 1][y][z] == 'E') && visit[x - 1][y][z] == -1)	//북
			{
				visit[x - 1][y][z] = visit[x][y][z] + 1;
				if (building[x - 1][y][z] == 'E')
				{
					flag = 1;
					break;
				}
				person.push_back({ x - 1,{ y,z } });
			}

			if (z - 1 >= 0 && (building[x][y][z - 1] == '.' || building[x][y][z - 1] == 'E') && visit[x][y][z - 1] == -1)	//하
			{
				visit[x][y][z - 1] = visit[x][y][z] + 1;
				if (building[x][y][z - 1] == 'E')
				{
					flag = 1;
					break;
				}
				person.push_back({ x ,{ y,z - 1} });
			}

			if (z + 1 < L && (building[x][y][z + 1] == '.' || building[x][y][z + 1] == 'E') && visit[x][y][z + 1] == -1)	//상
			{
				visit[x][y][z + 1] = visit[x][y][z] + 1;
				if (building[x][y][z + 1] == 'E')
				{
					flag = 1;
					break;
				}
				person.push_back({ x ,{ y,z + 1 } });
			}

		}//while( person.empty)
		person.clear();/////////////////////////중요!!!!

		if (flag == 1)
		{
			cout << "Escaped in " << visit[end_x][end_y][end_z] << " minute(s)." << endl;
		}

		else
			cout << "Trapped!" << endl;
	}// while (1)
	return 0;
}