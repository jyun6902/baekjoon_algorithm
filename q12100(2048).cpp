#include <iostream>
using namespace std;
int board[22][22];

int sum = 2, result = 2;
int N;
int game(int board[][22], int count, int direction)	//N= 배열크기, direction 왼=1 오=2 아래=3 위=4
{

	int board_copy[22][22];
	if (count >= 5)
		return result;
	else
		count++;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			board_copy[i][j] = board[i][j];
	}

	if (direction == 1)	//왼쪽
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board_copy[i][j] == 0)
				{
					for (int k = j + 1; k < N; k++)
					{
						if (board_copy[i][k] != 0)
						{
							board_copy[i][j] = board_copy[i][k];
							board_copy[i][k] = 0;
							k = N - 1;
						}
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				if (board_copy[i][j] == board_copy[i][j + 1])
				{
					board_copy[i][j] = board_copy[i][j] + board_copy[i][j + 1];
					board_copy[i][j + 1] = 0;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board_copy[i][j] == 0)
				{
					for (int k = j + 1; k < N; k++)
					{
						if (board_copy[i][k] != 0)
						{
							board_copy[i][j] = board_copy[i][k];
							board_copy[i][k] = 0;
							k = N - 1;
						}
					}
				}
			}
		}


	}

	else if (direction == 2)	//오른쪽
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >0; j--)
			{
				if (board_copy[i][j] == 0)
				{
					for (int k = j - 1; k >= 0; k--)
					{
						if (board_copy[i][k] != 0)
						{
							board_copy[i][j] = board_copy[i][k];
							board_copy[i][k] = 0;
							k = 0;
						}
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >0; j--)
			{
				if (board_copy[i][j] == board_copy[i][j - 1])
				{
					board_copy[i][j] = board_copy[i][j] + board_copy[i][j - 1];
					board_copy[i][j - 1] = 0;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >0; j--)
			{
				if (board_copy[i][j] == 0)
				{
					for (int k = j - 1; k >= 0; k--)
					{
						if (board_copy[i][k] != 0)
						{
							board_copy[i][j] = board_copy[i][k];
							board_copy[i][k] = 0;
							k = 0;
						}
					}
				}
			}
		}	//for i

	}

	else if (direction == 3)	//남쪽
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >0; j--)
			{
				if (board_copy[j][i] == 0)
				{
					for (int k = j - 1; k >= 0; k--)
					{
						if (board_copy[k][i] != 0)
						{
							board_copy[j][i] = board_copy[k][i];
							board_copy[k][i] = 0;
							k = 0;
						}
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >0; j--)
			{
				if (board_copy[j][i] == board_copy[j - 1][i])
				{
					board_copy[j][i] = board_copy[j][i] + board_copy[j - 1][i];
					board_copy[j - 1][i] = 0;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >0; j--)
			{
				if (board_copy[j][i] == 0)
				{
					for (int k = j - 1; k >= 0; k--)
					{
						if (board_copy[k][i] != 0)
						{
							board_copy[j][i] = board_copy[k][i];
							board_copy[k][i] = 0;
							k = 0;
						}
					}
				}
			}
		}

	}

	else if (direction == 4)	//위쪽
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board_copy[j][i] == 0)
				{
					for (int k = j + 1; k < N; k++)
					{
						if (board_copy[k][i] != 0)
						{
							board_copy[j][i] = board_copy[k][i];
							board_copy[k][i] = 0;
							k = N - 1;
						}
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N - 1; j++)
			{
				if (board_copy[j][i] == board_copy[j + 1][i])
				{
					board_copy[j][i] = board_copy[j][i] + board_copy[j + 1][i];
					board_copy[j + 1][i] = 0;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board_copy[j][i] == 0)
				{
					for (int k = j + 1; k < N; k++)
					{
						if (board_copy[k][i] != 0)
						{
							board_copy[j][i] = board_copy[k][i];
							board_copy[k][i] = 0;
							k = N - 1;
						}
					}
				}
			}
		}


	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (sum < board_copy[i][j])
				sum = board_copy[i][j];
		}
	}

	if (sum > result)
		result = sum;

	game(board_copy, count, 1);
	game(board_copy, count, 2);
	game(board_copy, count, 3);
	game(board_copy, count, 4);


	//return result;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	game(board, 0, 1);
	game(board, 0, 2);
	game(board, 0, 3);
	game(board, 0, 4);

	cout << result;

	return 0;
}