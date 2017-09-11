#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int k = 0, cnt = 0;//2<=k<=9
	char sign[11];
	cin >> k;
	vector <int> v(k + 1);
	for (int i = 0; i < k; i++)
		cin >> sign[i];
	///////////////////////////////////////////////ÃÖ´ñ°ª
	for (int i = 0; i <= k; i++)
		v[i] = 9 - i;

	do
	{
		for (int i = 0; i < k; i++)
		{
			if ((sign[i] == '<' && v[i] < v[i + 1]) || (sign[i] == '>' && v[i] > v[i + 1]))
				cnt++;

			else
				break;
		}

		if (cnt == k)
		{
			for (int i = 0; i <= k; i++)
				cout << v[i];
			cout << endl;
			break;
		}
		cnt = 0;
	} while (prev_permutation(v.begin(), v.end()));
	///////////////////////////////////////////////ÃÖ¼Ú°ª
	vector <int> v2(k + 1);
	v = v2;
	for (int i = 0; i <= k; i++)
		v[i] = i;
	cnt = 0;
	do
	{
		for (int i = 0; i < k; i++)
		{
			if ((sign[i] == '<' && v[i] < v[i + 1]) || (sign[i] == '>' && v[i] > v[i + 1]))
				cnt++;

			else
				break;
		}

		if (cnt == k)
		{
			for (int i = 0; i <= k; i++)
				cout << v[i];
			cout << endl;
			break;
		}
		cnt = 0;
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}