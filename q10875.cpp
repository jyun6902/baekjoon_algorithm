#include <iostream>
#include <cstring>

using namespace std;
long long int L;

int N;	//È¸Àü¼ö
int point[1001][2];	//point[0][0] =xÁÂÇ¥, point[0][1] =yÁÂÇ¥
int number[1001];
char letter[1001];
int h_line[1001][4];
int v_line[1001][4];
int i=1;
int cal_area(int first_dir, int num, char second_dir)	//num = ¸î¹øÂ°ÀÎÁö second_dir = ¹æÇâ(L R)
{
	if (num % 4 == 1)	//µ¿ÂÊ xÁÂÇ¥
	{
		point[num][0] = point[num-1][0] + first_dir;
		point[num][1] = point[num - 1][1];
		
	}

	else if ( (num %4 == 2 && second_dir == 'L') || (num % 4 == 0 && second_dir == 'R'))	//ºÏÂÊ yÁÂÇ¥
	{
		point[num][1] = point[num - 1][1]+first_dir;
		point[num][0] = point[num - 1][0];
	}

	else if ( (num % 4 == 2 && second_dir == 'R') || (num % 4 == 0 && second_dir == 'L'))	//³²ÂÊ yÁÂÇ¥
	{
		point[num][1] = point[num - 1][1] -first_dir;
		point[num][0] = point[num - 1][0];
	}

	else if (num % 4 == 3 )	//¼­ÂÊ  xÁÂÇ¥
	{
		point[num][0] = point[num - 1][0]-first_dir;
		point[num][1] = point[num - 1][1];
	}

	while (i != N+1)
	{
		cout << "i= "<< i <<" num= "<<num <<" " << point[i][0] <<" " << point[i][1] << endl;
		i++;
		num++;
		cal_area(number[i], num, letter[i - 1]);
	}

	return 0;
}

int main()
{
	cin >> L >> N;
	memset(point, 0, sizeof(point));
	memset(number, 0, sizeof(number));
	for (int i = 1; i <= N ; i++)
		cin >> number[i] >> letter[i];

	cal_area(number[1], 1, 'L');	//num = ¸î¹øÂ°ÀÎÁö second_dir = ¹æÇâ(L R)

	
	return 0;
}