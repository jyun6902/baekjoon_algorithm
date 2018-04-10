#include <iostream>
#include <cstdio>
#include <cstring>
int N = 0;
int max_result = 0;
int day[16]={};
int fee[16] = {};
//배열사이즈 확인!
void cal(int now, int sum)
{
	if (now <= N)
	{
		if (max_result < sum)
			max_result = sum;
	}

	if (now >= N)
		return;

	cal(now + day[now+1], sum + fee[now+1]);
	cal(now + 1, sum );
	return;
}

int main()
{
	scanf("%d", &N);
	memset(day, 0, sizeof(day));
	memset(fee, 0, sizeof(fee));
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &day[i], &fee[i]);

	cal(0, 0);
	printf("%d\n", max_result);
	return 0;
}