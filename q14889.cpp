#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	int N = 0;//4 ≤ N ≤ 20
	int arr[21][21] = {};
	int check[21] = {};
	int min_result = 987654321;
	int start = 0, link = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < (1 << N); i++)//make_combination
	{
		vector <int> d;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
				d.push_back(j);
		}
		if (d.size() == N / 2)//N/2로 만들어졌을경우
		{
			memset(check, 0, sizeof(check));
			start = 0;
			link = 0;
			int a, b = 0;
			for (int j = 0; j < d.size(); j++)
			{
				a = d.at(j);
				for (int k = 0; k < d.size(); k++)
				{
					b = d.at(k);
					if (a == b)
						continue;
					check[a] = check[b] = 1;
					start += arr[a][b];
				}
			}

			vector <int> p;
			for (int j = 0; j < N; j++)//start아닌것 
			{
				if (check[j] == 0)
					p.push_back(j);
			}

			for (int j = 0; j < p.size(); j++)
			{
				a = p.at(j);
				for (int k = 0; k < p.size(); k++)
				{
					b = p.at(k);
					if (a == b)
						continue;

					link += arr[a][b];
				}
			}

			if (abs(start - link) < min_result)
				min_result = abs(start - link);
		}
	}
	cout << min_result << endl;
	return 0;
}