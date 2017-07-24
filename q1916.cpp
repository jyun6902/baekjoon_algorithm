#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <climits>
using namespace std;
//(1≤V≤20,000, 1≤E≤300,000)
vector <pair<int, int>> adj[20001];	//그래프 인접리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담음

vector<int> dijkstra(int src, int V, int E)//from, to, value
{
	vector <int> dist(V, INT_MAX);	//vector v(n,x) ; v는 x 값으로 초기화된 n개의 원소를 갖는다.
	dist[src] = 0;

	priority_queue <pair<int, int>> pq;
	pq.push({ 0,src });

	while (!pq.empty())
	{
		int cost = -pq.top().first;	//비용이 가장 작은 것 부터 pop
		int from = pq.top().second;	//src

		pq.pop();

		if (dist[from] < cost)
			continue;		//지금 꺼낸 것보다 더 짧은 경로가 이미 존재할때

		for (int i = 0; i < adj[from].size(); i++)	//연결된 간선 만큼 for
		{
			int to = adj[from][i].first;//adj[from]에 들어있는 것중 i번째 index
			int next_cost = cost + adj[from][i].second;//value

			if (dist[to] > next_cost)
			{
				dist[to] = next_cost;
				pq.push({ -next_cost, to });
			}
		}
	}
	return dist;
}

int main()
{
	int n, m = 0;//(1≤V≤20,000, 1≤E≤300,000)
	int start = 0, end = 0;

	cin >> n >> m;

	n += 1;	//정점의 개수 1부터 시작
	for (int i = 0; i < m; i++)
	{
		int from, to, result;
		cin >> from >> to >> result;
		adj[from].push_back({ to, result });
	}
	cin >> start >> end;

	vector<int> answer = dijkstra(start, n, m);
	cout << answer[end] << endl;
	return 0;
}