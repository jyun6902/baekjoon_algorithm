#include <iostream>
#include <cmath>
using namespace std;
int dir[101];
int num[101];
#define min_2(a, b) ( a>b? b:a)
int main()
{
	int h, w = 0, n=0, sum=0;
	int x_dir, x_num = 0;
	cin >> w >> h >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> dir[i] >> num[i];
	}
	cin >> x_dir>> x_num;
	
	for (int i = 1; i <= n ; i++)
	{
		if (x_dir == 1)	//ºÏ
		{
			if (dir[i] == 1)
				sum += abs(x_num - num[i]);

			else if (dir[i] == 2)
			{
				int a=  (num[i] + x_num + h);
				sum += min_2(a, 2*w+2*h - a);
			}
			else if (dir[i] == 3)
				sum += (x_num + num[i]);

			else if (dir[i] == 4)
				sum += (w - x_num + num[i]);
		}

		else if (x_dir == 2)	//³²
		{
			if (dir[i] == 1)
			{
				int a = (num[i] + x_num + h);
				sum += min_2(a, 2 * w + 2 * h - a);
			}
			else if (dir[i] == 2)
				sum += abs(x_num - num[i]);

			else if (dir[i] == 3)
				sum += (x_num + h - num[i]);

			else if (dir[i] == 4)
				sum += (w - x_num + h - num[i]);
		}

		else if (x_dir == 3)	//¼­
		{
			if (dir[i] == 1)
				sum += (x_num + num[i]);

			else if ( dir[i] == 2)
				sum += (h - x_num + num[i]);

			else if ( dir[i] == 3)
				sum+= abs(x_num - num[i]);

			else if (dir[i] == 4)
			{
				int a = w + x_num + num[i];
				sum += (a, 2 * w + 2 * h - a);
			}
		}

		else if (x_dir == 4)	//µ¿
		{
			if (dir[i] == 1)
				sum += x_num + w - num[i];
			else if (dir[i] == 2)
				sum += w - num[i] + h - x_num;
			else if (dir[i] == 3)
			{
				int a = w+ x_num + num[i];
				sum += (a, 2 * w + 2 * h - a);
			}

			else if (dir[i] == 4)
				sum += abs(x_num - num[i]);
		}
	}
	
	cout << sum << endl;
	return 0;
}