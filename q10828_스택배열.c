#include <stdio.h>
#include <string.h>

int main()
{
	int N = 0, i = 0, num = 0;//¸í·É¼ö
	int cnt = 0;
	int arr[10001];
	char order[10];
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", order);

		if (strcmp(order, "push") == 0)
		{
			scanf("%d", &num);
			arr[++cnt] = num;
		}

		if (strcmp(order, "pop") == 0)
		{
			if (cnt == 0)
				printf("-1\n");
			else
			{
				printf("%d\n", arr[cnt]);
				arr[cnt] = 0;
				cnt--;
			}
		}

		else if (strcmp(order, "size") == 0)
			printf("%d\n", cnt);

		else if (strcmp(order, "empty") == 0)
		{
			if (cnt == 0)
				printf("1\n");
			else
				printf("0\n");
		}

		else if (strcmp(order, "top") == 0)
		{
			if (cnt == 0)
				printf("-1\n");
			else
				printf("%d\n", arr[cnt]);
		}
	}
	return 0;
}