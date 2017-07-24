#include <iostream>
#include <deque>
#include <string>

using namespace std;
string map[1004];

int main()
{
	int T = 0; //  테스트개수

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		deque <pair<int, int>> person;
		deque <pair<int, int>> next_person;
		deque <pair<int, int>> fire;
		deque <pair<int, int>> next_fire;
		bool find = false;
		int w = 0, h = 0;		// 너비, 높이
		int sec = 1;		// 초
		cin >> w >> h;

		for (int i = 1; i <= h; i++)
		{
			cin >> map[i];
			map[i] = '!' + map[i] + '!';
		}
		string temp = "";
		for (int i = 0; i <= w + 1; i++)
		{
			temp += "!";
		}
		map[0] = temp;
		map[h + 1] = temp;

		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (map[i][j] == '*')
					fire.push_back(make_pair(i, j));
				else if (map[i][j] == '@')
				{
					if (i == 1 || i == h || j == 1 || j == w)
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
				if (map[now.first][now.second + 1] != '#' && map[now.first][now.second + 1] != '!'&& map[now.first][now.second + 1] != '*')	//동
				{
					map[now.first][now.second + 1] = '*';
					next_fire.push_back(make_pair(now.first, now.second + 1));
				}

				if (map[now.first][now.second - 1] != '#' && map[now.first][now.second - 1] != '!' && map[now.first][now.second - 1] != '*')	//서
				{
					map[now.first][now.second - 1] = '*';
					next_fire.push_back(make_pair(now.first, now.second - 1));
				}

				if (map[now.first + 1][now.second] != '#' && map[now.first + 1][now.second] != '!' && map[now.first + 1][now.second] != '*')	//남
				{
					map[now.first + 1][now.second] = '*';
					next_fire.push_back(make_pair(now.first + 1, now.second));
				}

				if (map[now.first - 1][now.second] != '#' && map[now.first - 1][now.second] != '!' && map[now.first - 1][now.second] != '*')	//북
				{
					map[now.first - 1][now.second] = '*';
					next_fire.push_back(make_pair(now.first - 1, now.second));
				}
			}

			while (!person.empty() && !find)
			{
				pair<int, int> now = person.front();
				person.pop_front();
				if (map[now.first][now.second + 1] == '.')	//동
				{
					map[now.first][now.second + 1] = '@';
					if ((now.first == 1 || now.first == h) || (now.second + 1 == w))
					{
						find = true;
					}
					next_person.push_back({ now.first,now.second + 1 });
				}

				if (map[now.first][now.second - 1] == '.')	//서
				{
					map[now.first][now.second - 1] = '@';
					if ((now.first == 1 || now.first == h) || (now.second - 1 == 1))
					{
						find = true;
					}
					next_person.push_back({ now.first,now.second - 1 });
				}

				if (map[now.first + 1][now.second] == '.')	//남
				{
					map[now.first + 1][now.second] = '@';
					if ((now.first + 1 == h) || (now.second == w || now.second == 1))
					{
						find = true;
					}
					next_person.push_back({ now.first + 1,now.second });
				}

				if (map[now.first - 1][now.second] == '.')	//북
				{
					map[now.first - 1][now.second] = '@';
					if ((now.first - 1 == 1) || (now.second == w || now.second == 1))
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
		/*	cout << "=======================================" << endl;
			for (int i = 0; i <= h + 1; i++)
			{
				for (int j = 0; j <= w + 1; j++)
				{
					cout << map[i][j] << ' ';
				}
				cout << endl;
			}
			cout << "=======================================" << endl;
			*/
		}

		if (find)
			cout << sec << endl;
		else if (person.empty())
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}