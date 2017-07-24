#include <iostream>
#include <cstring>
using namespace std;

int num[1005][1005];
int C=0, R=0;
int main()
{
	memset(num, 0, sizeof(num));
	int K = 0, side = 0;
	int x = 1, y = 1;
 	cin >> C >> R;
	int answer = 1;

	cin >> K;

	if (K > C*R)
	{
		cout << "0" << endl;
		return 0;
	}
	else
	{
		while (++side)
		{
			
			if (K < answer + 2 * (R + C) - (8 * (side - 1)) - 4)
			{
				break;	
			}

			else 
				answer += 2 * (R + C) - (8 * (side-1)) - 4;

		}
		//answer +1
		x = side;
		y = side;
		int v = R - (2 * (side-1))-1;
		int h = C - (2 * (side-1))-1;
		int temp = K - answer;
		for (int i = 0; i < v; i++)
		{
			if (temp == 0)
				break;
			y++;
			temp--;
		}

		for (int i = 0; i < h; i++)
		{
			if (temp == 0)
				break;
			x++;
			temp--;
		}

		for (int i = 0; i < v; i++)
		{
			if (temp == 0)
				break;
			y--;
			temp--;
		}

		for (int i = 0; i < h; i++)
		{
			if (temp == 0)
				break;
			x--;
			temp--;
		}

		cout << x << " " << y << endl;
	}
	return 0;
}