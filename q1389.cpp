#include <iostream>
using namespace std;
int relation[101][101];

int main()
{
	int N = 0; //유저의 수
	int M = 0; //친구 관계의 수
	int a = 0, b = 0;
	int min_result = 5000;
	int result[101] = { 0, };
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
				relation[i][j] = 99999;
			if (i == j)
				relation[i][j] = 0;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		relation[a][b] = 1;
		relation[b][a] = 1;
	}

	for (int k = 1;  k <= N; k++)		//floyd algorithm
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1 ; j <= N; j++)
			{
				if (relation[i][k] + relation[k][j] < relation[i][j])
					relation[i][j] = relation[i][k] + relation[k][j];
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			result[i] += relation[i][j];
		}

		if (result[i] < min_result)
		{
			min_result = result[i];
			answer = i;
		}
	}
	cout << answer << endl;
	return 0;
}