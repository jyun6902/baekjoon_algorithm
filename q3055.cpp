#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque <pair<int, int>> water;
deque <pair<int, int>> n_water;
deque <pair<int, int>> dochi;
deque <pair<int, int>> n_dochi;

int main()
{
	int R = 0, C = 0;
	int min = 0; 
	string maps[55];
	bool find = false;
	cin >> R >> C;	//R행 C열

	for (int i = 1; i <= R; i++)
	{
		cin >> maps[i];
		maps[i] = '!' + maps[i] + '!';
	}
	
	string temp = "";
	for (int i = 0; i <= C + 1; i++)
	{
		temp += "!";
	}

	maps[0] = temp;
	maps[R + 1] = temp;
	
	for (int i = 1; i <= R ; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (maps[i][j] == 'S')		//고슴도치 위치
			{
				dochi.push_back({ i,j });
			}
			else if (maps[i][j] == '*')		//물 위치
			{
				water.push_back({ i,j });
			}
		}
	}
	
	while (!dochi.empty() && !find)
	{
		while (!water.empty() && !find )	//물
		{
			if (maps[water.front().first][water.front().second + 1] != 'D' && maps[water.front().first][water.front().second + 1] != 'X' && maps[water.front().first][water.front().second + 1] != '*' && maps[water.front().first][water.front().second + 1] != '!')	//동
			{
				maps[water.front().first][water.front().second + 1] = '*';
				n_water.push_back({ water.front().first , water.front().second + 1 });
			}

			if (maps[water.front().first][water.front().second - 1] != 'D' && maps[water.front().first][water.front().second - 1] != 'X' && maps[water.front().first][water.front().second - 1] != '*' && maps[water.front().first][water.front().second - 1] != '!')	//서
			{
				maps[water.front().first][water.front().second - 1] = '*';
				n_water.push_back({ water.front().first , water.front().second -1 });
			}

			if (maps[water.front().first + 1][water.front().second] != 'D' && maps[water.front().first + 1][water.front().second] != 'X' && maps[water.front().first + 1][water.front().second] != '*' && maps[water.front().first + 1][water.front().second] != '!')	//남
			{
				maps[water.front().first + 1][water.front().second] = '*';
				n_water.push_back({ water.front().first + 1 , water.front().second });
			}

			if (maps[water.front().first - 1][water.front().second] != 'D' && maps[water.front().first - 1][water.front().second] != 'X' && maps[water.front().first - 1][water.front().second] != '*'  && maps[water.front().first - 1][water.front().second] != '!')	//북
			{
				maps[water.front().first - 1][water.front().second] = '*';
				n_water.push_back({ water.front().first - 1 , water.front().second });
			}
			water.pop_front();
		}

		while (!dochi.empty() && !find )
		{
			if (maps[dochi.front().first][dochi.front().second + 1] == 'D')	//동
			{
				find = true;
			}

			if (maps[dochi.front().first][dochi.front().second - 1] == 'D')	//서
			{
				find = true;
			}

			if (maps[dochi.front().first + 1][dochi.front().second] == 'D')	//남
			{
				find = true;
			}

			if (maps[dochi.front().first - 1][dochi.front().second] == 'D')	//북
			{
				find = true;
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////
			if (maps[dochi.front().first][dochi.front().second + 1] == '.' )	//동
			{
				maps[dochi.front().first][dochi.front().second + 1] = 'S';
				n_dochi.push_back({ dochi.front().first, dochi.front().second + 1 });
			}

			if (maps[dochi.front().first][dochi.front().second - 1] == '.')	//서
			{
				maps[dochi.front().first][dochi.front().second - 1] = 'S';
				n_dochi.push_back({ dochi.front().first, dochi.front().second - 1 });
			}

			if (maps[dochi.front().first + 1][dochi.front().second] == '.')	//남
			{
				maps[dochi.front().first + 1][dochi.front().second] = 'S';
				n_dochi.push_back({ dochi.front().first + 1 , dochi.front().second});
			}

			if (maps[dochi.front().first - 1][dochi.front().second] == '.')	//북
			{
				maps[dochi.front().first - 1][dochi.front().second] = 'S';
				n_dochi.push_back({ dochi.front().first - 1 , dochi.front().second });
			}
			dochi.pop_front();

			///////////////////////////////////////////////////////////////////////////////////
		}

		if (find)
		{
			min++;
			break;
		}

		dochi = n_dochi;
		water = n_water;
		deque <pair<int, int>> n_water_clear;
		deque <pair<int, int>> n_dochi_clear;
		n_water = n_water_clear;
		n_dochi = n_dochi_clear;
		min++;

		/*cout << "=================================" << endl;
		for (int i = 0; i <= R + 1; i++)
		{
			for (int j = 0; j <= C + 1; j++)
			{
				cout << maps[i][j] << " ";
			}
			cout << endl;
		}*/
	}

	if (find)
		cout << min << endl;

	else if (dochi.empty())
		cout << "KAKTUS" << endl;

	return 0;
}