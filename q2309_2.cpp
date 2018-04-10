#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int dwarf[9] = {};
int real_dwarf[7] = {};
int flag = 0;
void cal(int now, int sum, int cnt)
{
	if (sum == 100)
	{
		if (cnt == 7)
		{
			flag = 1;
			for (int i = 0; i < 7; i++)
				printf("%d\n", real_dwarf[i]);
			printf("\n");
		}
		return;
	}


	if (flag == 1)
		return;
	if (sum > 100 || cnt > 7)
		return;

	for (int i = now; i < 9; i++)
	{
		real_dwarf[now] = dwarf[i];
		cal(now + 1, sum + real_dwarf[now], cnt + 1);
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		scanf("%d", &dwarf[i]);
	sort(dwarf, dwarf + 9);
	cal(0, 0, 0);// cal(int now, int sum, int cnt)
	return 0;
}