#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> line;
int main()
{
	int N = 0, t = 0, sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> t;
		line.push_back(t);
	}

	sort(line.begin(), line.end());

	for (int i = 0; i < N - 1; i++)
		line[i + 1] += line[i];

	for (int i = 0; i < N; i++)
		sum += line[i];

	cout << sum << endl;
	return 0;
}