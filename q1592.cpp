#include <iostream>
using namespace std;

int main()
{
	int N, M, L = 0;	//N=사람수 M=공을 M번받아 끝나는 곳 L=L번만큼 좌우로 이동
	int arr[1001] = { 0 };	//카운트저장
	int now = 1, cnt = 0;
	arr[1] = 1;	//1번부터 시작
	cin >> N >> M >> L;

	while (1)
	{
		if (arr[now] == M)
			break;

		if (arr[now] % 2 == 1)	//홀수일 경우 -> 오른쪽으로 L만큼 이동
		{
			if (now + L > N)
				now = (now + L) - N;

			else
				now += L;
		}

		else //짝수일 경우 -> 왼쪽으로 L만큼 이동
		{
			if (now - L <= 0)
				now = N + (now - L);

			else
				now -= L;
		}

		arr[now] ++;
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}