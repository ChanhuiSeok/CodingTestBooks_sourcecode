#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

/* 18352번 - 다익스트라 풀이 */

#define INF 987654321
#define pii pair<int, int>

using namespace std;

int dist[300001];

vector<vector<pii>> path;
priority_queue<pii, vector<pii>, greater<pii>> pq; //min-heap

void dijkstra(int v) {

	// 시작
	dist[v] = 0;
	pq.push({ dist[v], v });

	while (!pq.empty()) {
		int distance = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		// 큐에서 가장 맨 앞의 것과 연결된 모든 노드를 확인하면서 거리값 업데이트
		for (int i = 0; i < path[curNode].size(); i++) {
			int nextNode = path[curNode][i].first;
			int nextDistance = path[curNode][i].second;

			if (dist[nextNode] < dist[curNode] + nextDistance)
				continue;

			if (dist[nextNode] > dist[curNode] + nextDistance) {
				dist[nextNode] = dist[curNode] + nextDistance;
				pq.push({ dist[nextNode], nextNode });
			}
		}	
	}

}


int main() {

	int N, M, K, X, a, b;
	// 도시개수, 도로개수, 거리정보, 출발도시번호

	cin >> N >> M >> K >> X;

	// 거리배열 초기화
	for (int i = 1; i <= N; i++) 
		dist[i] = INF;
	dist[X] = 0;

	path.resize(N + 1);

	for (int i = 0; i < M; i++) {
		// a to b
		cin >> a >> b;
		path[a].push_back({ b, 1 });
	}

	dijkstra(X);

	bool flag = false;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			cout << i << '\n';
			flag = true;
		}
	}

	if (!flag) cout << -1;

	return 0;
}