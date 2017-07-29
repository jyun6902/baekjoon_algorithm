#include <iostream>
using namespace std;

int main()
{
	int N = 0, m = 0, M = 0, T = 0, R = 0; //N=운동 시간, m=처음 맥박, M= 최대 올라갈 수 있는 맥박, T= 만큼 증가. R= 만큼 감소
	cin >> N >> m >> M >> T >> R;
	int min = 0, X = m, exercise = 0; //min = 걸리는 시간 X= 현재 맥박

	if (T > M - m)	//1분 운동할때 증가하는 맥박 > 최대-최소 심박수차이
	{
		cout << "-1" << endl;
		return 0;
	}

	while (1)
	{
		while (X + T <= M)	//운동시간
		{
			X += T;
			exercise++;
			min++;

			if (exercise == N)
			{
				cout << min << endl;
				return 0;
			}
		}

		if (X + T > M)//최대 올라갈수 있는 맥박 보다 큰경우
		{
			X -= R;
			min++;

			if (X <= m)
				X = m;
		}
	}
	return 0;
}