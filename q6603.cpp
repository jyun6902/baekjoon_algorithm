#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	while (1)
	{
		int n = 0;
		int lotto[13] = {};
		scanf("%d", &n);

		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
			scanf("%d", &lotto[i]);

		sort(lotto, lotto + n);
		vector <vector <int>> v;
		for (int i = 0; i < (1 << n); i++)
		{
			vector <int> v_sub;
			for (int j = 0; j < n; j++)
			{
				if (i& (1 << j))
					v_sub.push_back(lotto[j]);
			}

			if (v_sub.size() == 6)
				v.push_back(v_sub);
		}

		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < 6; j++)
				printf("%d ", v[i][j]);
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}