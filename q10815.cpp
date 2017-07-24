/*
sort할 필요 x
입력받은 값을 배열에 저장하고
num값 받으면서 배열에 있는지 체크
printf, scanf말고 cin,cout 써도 괜찮음
(속도는 더 느림)
*/
#include <iostream>
#include <cstdio>
using namespace std;
int card[20000001];
int num[20000001];
int N, M;	//N=상근이가 가지고 있는 숫자 카드의 개수. 

int main()
{
	int x = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		card[x+10000000] = 1;	//입력받은 배열을 1로 체크
	}
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &x);
		if (card[x + 10000000] == 1)	//입력받은 값이 존재할 경우
			num[i] = 1;
		else
			num[i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");

	return 0;
}