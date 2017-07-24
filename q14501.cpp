#include <iostream>
#include <cstring>
using namespace std;
int N = 0;
int coun[16][2];
int  max_result = 0;

int check(int result, int day, int ok)
{

	if (  coun[day][0] ==0  && ok == 1)
	{
		return 0;
	}

	if (ok ==1)
	{
		day = day+ coun[day][0];
		if (day > N )
		{
			if (max_result < result)
				max_result = result;

			result = 0;
			return 0;
		}

		check(result + coun[day][1], day, 1);
		check(result, day, 0);
	}

	else if (ok == 0)
	{
		day += 1;

		if (day > N)
		{
			if (max_result < result)
				max_result = result;

			result = 0;
			return 0;
		}
		check(result, day, 0);
		check(result + coun[day][1], day, 1);
	}
	
}

int main()
{
	cin >> N;
	memset(coun, 0, sizeof(coun));
	for (int i = 0; i < N; i++)
	{
		cin >> coun[i][0] >> coun[i][1]; //Ti Pi
		
		if (coun[i][0] + i > N)
		{
			coun[i][0] = 0;
		}
		
	}

	check(coun[0][1],0,1);	//1일 하는지
	check(0, 0, 0);	//안하는지
	
	cout << max_result;

	return 0;
}