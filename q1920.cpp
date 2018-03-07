#include <iostream>
#include <cstdio>

using namespace std;
int A[100001] = {};

void quick_sort(int left, int right)
{
	int i = left, j = right;
	int pivot = A[(left + right) / 2];

	do {
		while (A[i] < pivot)
			i++;

		while (A[j] > pivot)
			j--;

		if (i <= j)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}

	} while (i <= j);

		if (i < right)
			quick_sort(i, right);

		if (left < j )
			quick_sort(left, j);
}

int BinarySearch(int val, int low, int high)
{
	if (high < low)
		return -1;
	int mid = (low + high) / 2;

	if (val < A[mid])
		return BinarySearch(val, low, mid-1);
	else if (val > A[mid])
		return BinarySearch(val, mid+1, high);
	else
		return mid;

}


int main()
{
	int N = 0, M = 0;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	quick_sort(0, N - 1);

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int k = 0;
		scanf("%d", &k);
		if (BinarySearch(k, 0, N - 1) == -1)
			printf("0\n");
		else
			printf("1\n");
	}


	return 0;
}