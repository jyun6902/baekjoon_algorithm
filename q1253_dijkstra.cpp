#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
//(1≤V≤20,000, 1≤E≤300,000)
vector <pair<int, int>> adj[20001];	//그래프 인접리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담음

vector<int> dijkstra(int src, int V, int E)
{
	vector <int> dist(V, INT_MAX);	//vector v(n,x) ; v는 x 값으로 초기화된 n개의 원소를 갖는다.
	dist[src] = 0;

	priority_queue<pair<int, int >> pq;
	pq.push({ 0, src });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if (dist[here] < cost)	//// 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸것을 무시한다.
			continue;

		for (int i = 0; i < adj[here].size() ; i++)	//인접한 정점들 모두 검사
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			if (dist[there] > nextDist)	//더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣음
			{
				dist[there] = nextDist;
				pq.push({ -nextDist, there });	//우선순위 큐는 가장 큰 원소가 큐에가도록 구성. 거리부호 바꿔서 작은 거리부터 꺼내지게하기 위함
			}
		}
	}

	return dist;
}

int main()
{
	int V, E = 0;//(1≤V≤20,000, 1≤E≤300,000)
	int start = 0;

	cin >> V >> E >> start;

	V += 1;	//정점의 개수 1부터 시작
	for (int i = 0; i < E; i++)
	{
		int from, to, result;
		cin >> from >> to >> result;
		adj[from].push_back({to, result });
	}

	vector<int> answer = dijkstra(start, V, E);

	for (int i = 1; i < V; i++)
	{
		if (answer[i] == INT_MAX)
			cout << "INF" << endl;

		else
			cout << answer[i]<< endl;
	}
	////////////////////////////////////////////////////

	return 0;
}