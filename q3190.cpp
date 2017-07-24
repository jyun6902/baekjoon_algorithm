#include <iostream>
#include <cstring>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int board[105][105];
int order[105][2];
int N, K, L;
int result = 0;
deque<pair<int,int>> body;
int main()
{
	memset(board, 0, sizeof(board));
	memset(order, 0, sizeof(order));
	int x=1, y = 1;
	int cal_dir=0;	//방향
	int cal_count=1;

	cin >> N >> K; 

	for (int j = 0; j <= N+1; j++)
	{
		
		board[0][j] = 10;
		board[N+1][j] = 10;
		board[j][0] = 10;
		board[j][N+1] = 10;
	}


	for (int i = 1; i <= K; i++)
	{
		cin >> x >> y;
		board[x][y] = 1;
	}
	
	cin >> L;
	
	for (int i = 1; i <= L; i++)
	{
		string dir;
		cin >> order[i][0] >> dir;
		if (dir[0] == 'D')	//오른쪽일때 1
			order[i][1] = 1;

		else //왼쪽일때 0
			order[i][1] = 0;
	}

	x = 1, y = 1;
	body.push_front({ 1,1 });
	while (++result)
	{
		if (cal_dir == 0)	//동쪽
			y++;

		else if (cal_dir == 1) // 남쪽
			x++;

		else if (cal_dir == 2) //서쪽
			y--;

		else if (cal_dir == 3)	//북쪽
			x--;
		
		if (board[x][y] == 10  )	//밖에있을때
			break;
		int dead = 0;
		for (int i = 0; i < body.size(); i++)
		{
			if (body[i].first == x && body[i].second == y)
			{	
				dead++;
				break;
			}
		}
		if (dead == 1)
			break;


		if (board[x][y] == 1)	//사과 있을때
		{
			body.push_front({ x, y });
			board[x][y] = 0;
		}

		else if (board[x][y] == 0)	//사과없을때
		{
			body.push_front({ x,y });
			body.pop_back();
		}

		if (order[cal_count][0] == result)
		{
			if (order[cal_count][1] == 1) // 오른쪽
				cal_dir = (cal_dir + 1) % 4;

			else
			{
				cal_dir = (cal_dir + 3) % 4;
			}

			cal_count++;
		}
		
	}
	cout << result; 

	return 0;
}