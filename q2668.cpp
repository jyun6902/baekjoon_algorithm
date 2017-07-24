#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N = 0;
int arr[102] = { 0, };
int start = 0;
bool visit[102] = { false, };
deque <int> save;
void go(int from, int cnt)
{
	visit[from] = true;
	save.push_back(from);

	if (start == arr[from] && visit[arr[from]] == true)	//ex) index 5- result 5
		return;

	if (start != arr[from] && visit[arr[from]] == true)		//돌아왔는데 방문을 했을 경우
	{
		for (int i = 0; i < cnt; i++)		//cnt 값 만큼 빼냄
		{
			int k = save.back();
			save.pop_back();
			visit[k] = false;
		}
		return;
	}

	if (visit[arr[from]] == false)
		go(arr[from], cnt + 1);
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == false)
		{
			start = i;
			go(i, 1);
		}
	}
	cout << save.size() << endl;

	sort(save.begin(), save.end());
	for (auto iter = save.begin(); iter != save.end(); ++iter)
	{
		cout << *iter << endl;
	}
	return 0;
}