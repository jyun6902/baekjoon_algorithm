#include <stdio.h>
#include <stdlib.h>
int main()
{
	int N = 0, num = 0, i = 0,cnt=0, head=1,tail=0;
	char order[10];
	int arr[10001] ;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%s", order);

		if (strcmp(order, "push") == 0)
		{
			scanf("%d", &num);
			arr[++tail] = num;
			cnt++;
		}

		else if (strcmp(order, "pop") == 0)
		{
			if (cnt == 0)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", arr[head]);
				arr[head] = 0;
				head++;
				cnt--;
				
			}
		}

		else if (strcmp(order, "size") == 0)
		{
			printf("%d\n", cnt);
		}

		else if (strcmp(order, "empty") == 0)
		{
			if (cnt == 0)
				printf("1\n");
			else
				printf("0\n");
		}

		else if (strcmp(order, "front") == 0)
		{
			if (cnt == 0)
				printf("-1\n");

			else
				printf("%d\n", arr[head]);
		}

		else if (strcmp(order, "back") == 0)
		{
			if (cnt == 0)
				printf("-1\n");
			
			else
				printf("%d\n", arr[tail]);
		}
	}

	return 0;
}