#include <iostream>
using namespace std;

int main()
{
	int N, M = 0, result = 0,cnt = 0;
	char S[1000001] = {0};
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> S[i];

	for (int i = 0; i < M; i++)
	{
		if (S[i] == 'I' && S[i + 1] == 'O' && S[i + 2] == 'I')
		{
			cnt++;
			i++;
		}

		else
		{
			if (cnt >= N)
				result += cnt - N + 1;
			cnt = 0;
		}
	}
	cout << result << endl;
	return 0;
}