#include <iostream>
#include <cstring>
using namespace std;

int map[505][505];
int N, M = 0;	//N 세로 M 가로
int result = 0, max_result;
int main()
{
	memset(map, 0, sizeof(map));

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++)		//가로로 1자
	{

		for (int j = 1; j <= M - 3; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3])
				result = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
		}
	}

	for (int i = 1; i <= N - 3; i++)
	{
		for (int j = 1; j <= M; j++)		//세로로 1자
		{
			if (max_result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j])
				max_result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//정사각형
	{

		for (int j = 1; j <= M - 1; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1])
				result = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)		//L모양
	{

		for (int j = 1; j <= M - 1; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)		//L | -l 반대모양
	{

		for (int j = 2; j <= M; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)		//L | _|모양 ㄱ
	{
		for (int j = 2; j <= M; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j - 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j - 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)		//L | i- 반대모양
	{

		for (int j = 1; j <= M - 1; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//ㄴ |___모양
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2])
				result = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 2; i <= N; i++)		//ㄴ반대___l 모양
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2])
				result = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//|--- 모양
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2])
				result = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//---| 모양
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i + 1][j + 2] + map[i][j + 1] + map[i][j + 2])
				result = map[i][j] + map[i + 1][j + 2] + map[i][j + 1] + map[i][j + 2];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//ㅜ모양
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1])
				result = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 2; i <= N; i++)		//ㅗ모양 13
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1])
				result = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
		}
	}


	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 1; j <= M - 1; j++)		//ㅏ모양 14	/////////////////////////////////////////
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
		}
	}


	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 2; j <= M; j++)		//ㅓ모양 15	/////////////////////////////////////////

		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1])
				result = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1];
		}
	}


	if (max_result < result)
		max_result = result;

	/*
	ㅇ
	ㅇㅇ
	  ㅇ
	*/
	for (int i = 1; i <= N - 2; i++)		//|-|모양 16
	{
		for (int j = 1; j <= M - 1; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1])
				result = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
		}
	}


	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 2; i++)		//|-|모양 17
	{

		for (int j = 2; j <= M; j++)
		{
			if (result < map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1])
				result = map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j - 1];
		}
	}


	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//-|_모양 18
	{

		for (int j = 1; j <= M - 2; j++)
		{
			if (result < map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2])
				result = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
		}
	}

	if (max_result < result)
		max_result = result;

	for (int i = 1; i <= N - 1; i++)		//|-|모양 19
	{

		for (int j = 3; j <= M; j++)
		{
			if (result < map[i][j] + map[i][j - 1] + map[i + 1][j - 1] + map[i + 1][j - 2])
				result = map[i][j] + map[i][j - 1] + map[i + 1][j - 1] + map[i + 1][j - 2];
		}
	}


	if (max_result < result)
		max_result = result;
	cout << max_result;

	return 0;
}