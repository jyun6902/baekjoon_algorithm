#include <iostream>
#include <deque>
#include <string>
using namespace std;

string maps[54];
int main()
{
	int h, w;
	int max_time = 0;
	cin >> h >> w;

	for (int i = 1; i <= h; i++)
	{
		cin >> maps[i];
		maps[i] = " "+ maps[i]+" ";
	}
	maps[0] = "                                                      ";
	maps[h+1] = "                                                      ";
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			deque <pair<int, int>> land;
			deque <pair<int, int>> n_land;
			string maps_temp[54];
			int counter = -1;
			copy(maps, maps + 54, maps_temp);
			if (maps_temp[i][j] == 'L')
			{
				land.push_back({ i,j });
			}
			while (!land.empty())
			{
				if (maps_temp[land.back().first][land.back().second+1] == 'L')	//µ¿
				{
					n_land.push_back({ land.back().first,land.back().second + 1 });
					maps_temp[land.back().first][land.back().second + 1] = 'W';
				}
				if (maps_temp[land.back().first][land.back().second - 1] == 'L')	//¼­
				{
					n_land.push_back({ land.back().first,land.back().second - 1 });
					maps_temp[land.back().first][land.back().second - 1] = 'W';
				}
				if (maps_temp[land.back().first+1][land.back().second] == 'L')	//³²
				{
					n_land.push_back({ land.back().first+ 1 ,land.back().second });
					maps_temp[land.back().first + 1][land.back().second ] = 'W';
				}
				if (maps_temp[land.back().first - 1][land.back().second] == 'L')	//ºÏ
				{
					n_land.push_back({ land.back().first - 1,land.back().second });
					maps_temp[land.back().first - 1][land.back().second] = 'W';
				}
				land.pop_back();
				
				if (land.empty())
				{
					land = n_land;
					deque <pair<int, int>> n_land_clear;
					n_land = n_land_clear;
					counter++;
				}
			}
			if (counter > max_time)
				max_time = counter;
		}

	}
	cout << max_time << endl; 
	return 0;
}
