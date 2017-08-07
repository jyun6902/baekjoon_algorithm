#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int maps[101][101] = { 0 };
	int X[101] = { 0 };				//방향변환 정보 숫자
	char C[101] = { 0 };	//방향변환 정보 문자 L = 왼쪽 D = 오른쪽
	int N = 0, K = 0, L = 0;//N= 보드 크기, K = 사과 개수, L = 방향 변환 개수
	int sec = 0;
	deque <pair <int, int>> snake;

	cin >> N >> K;
	snake.push_back({ 1,1 });	//처음 시작할 때
	for (int i = 1; i <= K; i++)
	{
		int a, b = 0;
		cin >> a >> b;
		maps[a][b] = 2;	//사과가 있을 경우 2
	}

	cin >> L;
	for (int i = 1; i <= L; i++)
		cin >> X[i] >> C[i];

	int x = 1, y = 1, dir = 0, cnt = 1;

	while (++sec)
	{
		
		if (dir == 0)			//동
			y++;
		else if (dir == 1)		//남
			x++;
		else if (dir == 2)		//서
			y--;
		else if (dir == 3)		//북
			x--;

		if (x< 1 || x> N || y< 1 || y> N)	//바깥으로 나갔을 경우
		{
			cout << sec << endl;
			return 0;
		}

		for (int i = 0; i < snake.size(); i++)		//자기 자신 부딪혔을 경우  
		{
			if (snake[i].first == x && snake[i].second == y)
			{
				cout << sec << endl;
				return 0;
			}
		}

		if (maps[x][y] != 2)	//사과가 없을 경우
			snake.pop_back();	//꼬리 지워짐

		if (maps[x][y] == 2)	//사과 있을 경우
			maps[x][y] = 0;

		snake.push_front({ x,y });

		if (X[cnt] == sec)			//명령 초만큼 이동했을 경우
		{
			if (C[cnt] == 'D')	//오른쪽일 경우 
				dir = (dir + 1) % 4;
			else if (C[cnt] == 'L')
				dir = (dir + 3) % 4;
			cnt++;
		}

	}

	cout << sec << endl;
	return 0;
}