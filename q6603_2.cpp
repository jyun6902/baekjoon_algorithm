#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int lotto[13] = {};
int save[13] = {};
int N = 0;
void cal(int now, int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < 6; i++)
		{
				printf("%d ", save[i]);
		}
		printf("\n");
		return;
	}

	for (int i = now; i < N; i++)
	{
		save[cnt] = lotto[i];
		cal(i + 1, cnt + 1);

	}
}
int main()
{
	while (1)
	{
		scanf("%d", &N);

		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
			scanf("%d", &lotto[i]);

		sort(lotto, lotto + N);
		cal(0, 0);
		printf("\n");
	}

	return 0;
}