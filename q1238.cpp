/*
제한시간 : 1초
메모리제한 : 128MB
테스트케이스 : 1

*/
#include <iostream>

using namespace std;
int N = 0, M = 0, X = 0;
int T[1002][1002];

int main()
{
	cin >> N >> M >> X;		//학생수, 도로수, 목적지
	int x, y = 0, t = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			T[i][j] = 987654321;
			if (i== j)
			{
				T[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> x >> y >> t;	//시작점, 끝점, 소요시간
		if (T[x][y] > t)
		T[x][y] = t;
	}

	for (int k = 1; k <= N; k++)	//floyd k = 경유하는 지점 !!
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (T[i][k] +T[k][j] < T[i][j])
					T[i][j] = T[i][k] + T[k][j];
			}
		}
	}

	int max_result = 0;
	for (int i = 1; i <= N; i++)
	{
		if (T[X][i] + T[i][X] > max_result)
			max_result = T[X][i] + T[i][X];
	}

	cout << max_result << endl;
	return 0;
}