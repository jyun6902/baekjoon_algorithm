#include <iostream>
#include <deque>
#include <string>
using namespace std;
/*비트마스크!!
string은 memset 초기화x 에러남
*/
int N = 0, M = 0;	//N=세로 M=가로
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visit[52][52][1 << 7];
bool find = false;
string maps[52];
deque <pair<pair<int, int>, int>> minsik;	//minsik_x, minsik_y, key
int sec = 0;
int bfs()
{
	while (minsik.size())
	{
		int minsik_s = minsik.size();
		for (int t_case = 0; t_case < minsik_s; t_case++)
		{
			int x = minsik.front().first.first;
			int y = minsik.front().first.second;
			int key1 = minsik.front().second;
			minsik.pop_front();

			if (maps[x][y] == '1')    //탈출
				return sec;

			for (int i = 0; i < 4; i++)
			{
				int px = x + dx[i];
				int py = y + dy[i];

				if (px > N || px < 1 || py > M || py < 1 || maps[px][py] == '#')
					continue;

				if (maps[px][py] >= 'a' && maps[px][py] <= 'f')// a - f 열쇠일 경우
				{
					int pz = key1 | (1 << (maps[px][py] - 'a'));	//a|b 합집합 기존가지고있는 열쇠와 합침
					if (visit[px][py][pz] == true)
						continue;
					visit[px][py][pz] = true;
					minsik.push_back({ { px, py }, pz });//a|b ; 합집합 px,py좌표에서 가지고 있는 현재 열쇠들
				}

				else if (maps[px][py] >= 'A' && maps[px][py] <= 'F' && visit[px][py][key1] == false)// 방문안한 A - F
				{
					if (key1&(1 << maps[px][py] - 'A'))//키 있는지 검사
					{
						visit[px][py][key1] = true;
						minsik.push_back({ { px,py }, key1 });
					}
				}

				else if (visit[px][py][key1] == false)
				{
					visit[px][py][key1] = true;
					minsik.push_back({ { px,py }, key1 });
				}
			}//for 방향
		}// for minsik_size
		sec++;
	}//while
	return -1;
}
int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> maps[i];
		maps[i] = '!' + maps[i] + '!';
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (maps[i][j] == '0')
			{
				minsik.push_back({ { i,j }, 0 });
				visit[i][j][0] = true;
			}
		}
	}

	cout << bfs() << endl;
	return 0;
}