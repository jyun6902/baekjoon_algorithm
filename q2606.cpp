#include <iostream>
using namespace std;

int main()
{
	int N = 0; // 컴퓨터의수
	int M = 0; //쌍의 수
	int virus[101][101];
	int a, b = 0;
	int result = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			virus[i][j] = 99999;
			if (i == j)
				virus[i][j] = 0;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		virus[a][b] = 1;
		virus[b][a] = 1;
	}

	for (int k = 1; k <= N; k++)		//floyd algorithm
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (virus[i][k] + virus[k][j] < virus[i][j])
					virus[i][j] = virus[i][k] + virus[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (virus[1][i] != 99999 && virus[1][i] != 0)
			result++;
	}

	cout << result << endl;
	return 0;
}