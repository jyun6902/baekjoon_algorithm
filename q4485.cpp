/*
while안에 if, else로  N=0일 때와 아닐때 나눠야함
vector 허용되지않은 범위 들어가서 에러남
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

vector <pair<int, int>> adj[30000];
int dx[4] = { 1, -1, 0, 0 };	//동, 서, 남, 북
int dy[4] = { 0, 0, -1, 1 };
vector<int> dijkstra(int src, int k)
{
	vector <int> dist(k*k + 1, INT_MAX);
	dist[src] = 0;

	priority_queue <pair<int, int>> pq;
	pq.push({ 0,src });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int from = pq.top().second;

		pq.pop();
		if (dist[from] < cost)
			continue;

		for (int i = 0; i < adj[from].size(); i++)
		{
			int to = adj[from][i].first;
			int next_cost = cost + adj[from][i].second;

			if (dist[to] > next_cost)
			{
				dist[to] = next_cost;
				pq.push({ -next_cost, to });
			}
		}
	}
	return dist;
}


int num(int x, int y, int N)
{
	return ((x - 1)*N + y);
}
int main()
{
	int cnt = 0;
	int maps[127][127];
	int N = 125;		//2 ≤ N ≤ 125
	while (N != 0)
	{
		cin >> N;
		if (N == 0)
		{
			return 0;
		}
		else
		{
			for (int i = 1; i < 30000; i++)
			{
				adj[i].clear();
			}

			memset(maps, 0, sizeof(maps));
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
					cin >> maps[i][j];
			}

			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						int x = i + dx[k];
						int y = j + dy[k];

						if (x <= 0 || x > N || y <= 0 || y > N)
							continue;

						adj[num(i, j, N)].push_back({ num(x,y,N), maps[x][y] });
					}
				}//for j
			}//for i

			vector <int> answer = dijkstra(1, N);
			cout << "Problem " << ++cnt << ": " << answer[N*N] + maps[1][1] << endl;
		}//while
	}
	return 0;
}