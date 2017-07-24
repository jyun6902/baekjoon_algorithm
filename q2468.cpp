#include <iostream>
#include <cstring>
using namespace std;
int N;
int area[110][110];
int sink[110][110];
int check[110][110];
int result = 0, max_result = 0;
int count_area = 0;
int max_height = 0;
int cal_height(int area[][110], int height)
{

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (height >= area[i][j])
				sink[i][j] = 0;//가라앉는 지역
			else
				sink[i][j] = 1;
		}
	}

	return 0;
}


int cal(int sink[][110], int i, int j)
{
	check[i][j] = 1;

	if (sink[i - 1][j] == 1 && check[i - 1][j] != 1)
		cal(sink, i - 1, j);

	if (sink[i + 1][j] == 1 && check[i + 1][j] != 1)
		cal(sink, i + 1, j);

	if (sink[i][j + 1] == 1 && check[i][j + 1] != 1)
		cal(sink, i, j + 1);

	if (sink[i][j - 1] == 1 && check[i][j - 1] != 1)
		cal(sink, i, j - 1);

	if (i == N && j == N)
		return 0;


}

int main()
{

	memset(area, 0, sizeof(area));

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> area[i][j];
			if (max_height < area[i][j])
				max_height = area[i][j];
		}
	}

	for (int i = max_height; i >= 0; i--)
	{
		memset(check, 0, sizeof(check));
		memset(sink, 0, sizeof(sink));
		cal_height(area, i);
		result = 0;
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (sink[j][k] == 1 && check[j][k] == 0)
				{
					result++;
					cal(sink, j, k);
				}
			}


		}

		if (max_result < result)
			max_result = result;


	}
	cout << max_result << endl;
	return 0;
}