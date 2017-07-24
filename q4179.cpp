#include <iostream>
#include <deque>
#include <string>

using namespace std;
char map[1004][1004];

int main()
{
		deque <pair<int, int>> person;
		deque <pair<int, int>> next_person;
		deque <pair<int, int>> fire;
		deque <pair<int, int>> next_fire;
		bool find = false;
		int C = 0, R = 0;		// 너비, 높이
		int sec = 1;		// 초
		cin >> R >> C;

		for (int i = 1; i <= R; i++)
		{
			for (int j =1 ; j<= C ; j++)
			cin>> map[i][j];
		}
		
			for (int j = 0; j <= C+1; j++)
			{
				map[R+1][j] = '!';
				map[0][j] = '!';
			}
		
			for (int i = 0; i <= R+1; i++)
			{
				map[i][0] = '!';
				map[i][C+1] = '!';
			}

		for (int i = 1; i <=R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				if (map[i][j] == 'F')
					fire.push_back(make_pair(i, j));
				else if (map[i][j] == 'J')
				{
					if (i == 1 || i == R || j == 1 || j == C)
					{
						find = true;

					}
					person.push_back(make_pair(i, j));
				}
			}
		}

		while (!person.empty() && !find)
		{
			while (!fire.empty() && !find)
			{
				pair<int, int> now = fire.front();
				fire.pop_front();
				if (map[now.first][now.second + 1] != '#' && map[now.first][now.second + 1] != '!'&& map[now.first][now.second + 1] != 'F')	//동
				{
					map[now.first][now.second + 1] = 'F';
					next_fire.push_back(make_pair(now.first, now.second + 1));
				}

				if (map[now.first][now.second - 1] != '#' && map[now.first][now.second - 1] != '!' && map[now.first][now.second - 1] != 'F')	//서
				{
					map[now.first][now.second - 1] = 'F';
					next_fire.push_back(make_pair(now.first, now.second - 1));
				}

				if (map[now.first + 1][now.second] != '#' && map[now.first + 1][now.second] != '!' && map[now.first + 1][now.second] != 'F')	//남
				{
					map[now.first + 1][now.second] = 'F';
					next_fire.push_back(make_pair(now.first + 1, now.second));
				}

				if (map[now.first - 1][now.second] != '#' && map[now.first - 1][now.second] != '!' && map[now.first - 1][now.second] != 'F')	//북
				{
					map[now.first - 1][now.second] = 'F';
					next_fire.push_back(make_pair(now.first - 1, now.second));
				}
			}

			while (!person.empty() && !find)
			{
				pair<int, int> now = person.front();
				person.pop_front();
				if (map[now.first][now.second + 1] == '.')	//동
				{
					map[now.first][now.second + 1] = 'J';
					if ((now.first == 1 || now.first == R) || (now.second + 1 == C))
					{
						find = true;
					}
					next_person.push_back({ now.first,now.second + 1 });
				}

				if (map[now.first][now.second - 1] == '.')	//서
				{
					map[now.first][now.second - 1] = 'J';
					if ((now.first == 1 || now.first == R) || (now.second - 1 == 1))
					{
						find = true;
					}
					next_person.push_back({ now.first,now.second - 1 });
				}

				if (map[now.first + 1][now.second] == '.')	//남
				{
					map[now.first + 1][now.second] = 'J';
					if ((now.first + 1 == R) || (now.second == C || now.second == 1))
					{
						find = true;
					}
					next_person.push_back({ now.first + 1,now.second });
				}

				if (map[now.first - 1][now.second] == '.')	//북
				{
					map[now.first - 1][now.second] = 'J';
					if ((now.first - 1 == 1) || (now.second == C || now.second == 1))
					{
						find = true;
					}
					next_person.push_back({ now.first - 1,now.second });

				}
			}

			if (find)
			{
				sec++;
				break;
			}
			//////////////////////////////////////////////////////////

			fire = next_fire;
			person = next_person;
			deque < pair<int, int>> clear_fire;
			deque < pair<int, int>> clear_person;
			next_fire = clear_fire;
			next_person = clear_person;
			sec++;

		}

		if (find)
			cout << sec << endl;
		else if (person.empty())
			cout << "IMPOSSIBLE" << endl;

	return 0;
}