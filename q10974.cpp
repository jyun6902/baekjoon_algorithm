#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++)
		arr[i]=i+1;

	do
	{
		for (int i = 0; i < N; i++)
			printf("%d ", arr[i] );
		printf("\n");
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}