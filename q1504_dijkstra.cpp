#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
vector <pair<int, int>> adj[30000];
int N, E;	//N= 정점의 개수 E = 간선의 개수
int must_1, must_2;
long min_2(long a, long b)
{
	if (a < b)
		return a;
	else
		return b;
}
vector<long> dijkstra(int src, int V, int E)
{
	vector<long > dist(V, INT_MAX);
	dist[src] = 0;

	priority_queue<pair<int,int>> pq;
	pq.push({ 0,src });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();
		if (dist[here] < cost)
			continue;

		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (dist[there] > nextDist)
				dist[there] = nextDist;
			pq.push({ -nextDist,there });
		}
	}
	
	return dist;
}
int main()
{
	cin >> N >> E;
	N += 1;
	for (int i = 0; i < E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ to, cost });
		adj[to].push_back({ from, cost });
	}
	cin >> must_1 >> must_2; 
	vector<long > answer1 = dijkstra(1, N, E);
	vector<long > answer2 = dijkstra(must_1, N, E);
	vector<long > answer3 = dijkstra(must_2, N, E);
	
	long result = min_2(answer1[must_1] + answer2[must_2] + answer3[N-1], answer1[must_2] + answer3[must_1] + answer2[N - 1]);
	if (result > INT_MAX)
		cout << "-1" <<endl;
	else
		cout << result<<endl;
	return 0;
}