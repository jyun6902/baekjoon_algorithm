#include <iostream>
#include <cstring>
using namespace std;
int parking[5][101];
int main()
{
	int A, B, C;	//1´ë, 2´ë, 3´ë
	int a, b, max_b = 0;
	int result = 0;
	memset(parking, 0, sizeof(parking));
	cin >> A >> B >> C;

	for (int i = 1; i <= 3; i++)
	{
		cin >> a >> b;
		b -= 1;
		if (max_b < b)
			max_b = b;

		for (int j = a; j <= b; j++)
			parking[i][j] = 1;
	}

	for (int i = 1; i <= max_b; i++)
		parking[4][i] = parking[1][i] + parking[2][i] + parking[3][i];

	int count_b = 1;
	for (int i = 0; i <= max_b; i++)
	{
		if (parking[4][i] != parking[4][1 + i])
		{
			if (parking[4][i] == 1)
				result += A* count_b;
			else if (parking[4][i] == 2)
				result += (B * 2)*count_b;
			else if (parking[4][i] == 3)
				result += C * 3 * count_b;
			count_b = 1;
		}

		else
			count_b++;
	}

	cout << result << endl;
	return 0;
}