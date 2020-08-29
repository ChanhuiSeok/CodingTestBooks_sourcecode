#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

/* 다익스트라 */
int dist[100001];
vector<pair<int, int>> vec[100001];

void dijkstra(int start) {

	// 시작 노드의 거리는 0으로 설정
	dist[start] = 0;

	// 우선순위큐 선언
	priority_queue<pair<int, int>> pq;
	pq.push({ dist[start], start });

	while (!pq.empty()) {
		// 큐에서 뽑은 cur와, 거기에 음수를 곱해 양수로 만든 실제 거리를 저장한다.
		int cur = pq.top().second;
		int distance = pq.top().first * -1;
		pq.pop();

		// 이미 담긴 것보다 distance가 더 크면 skip
		if (dist[cur] < distance) continue;

		// 이 노드와 연결된 다른 모든 인접 노드를 확인한다.
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int nextDistance = distance + vec[cur][i].second;

			// 거쳐 가는 것이 바로 가는 것보다 짧을 경우
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push({ nextDistance * -1, next });
			}
		}
	}
}

int main() {

	int N, M, C;
	// 도시 개수 N, 통로 개수 M, 메세지를 보내고자 하는 도시 C
	cin >> N >> M >> C;

	// 1. 거리배열 초기화
	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	int X, Y, Z;
	for (int i = 0; i < M; i++) {
		cin >> X >> Y >> Z;
		vec[X].push_back({ Y,Z }); // X->Y 연결되고 그 간선의 가중치는 Z
	}

	dijkstra(C);

	int count = 0, max_dist = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] != INF) count += 1;
		// 도시들이 모두 메세지를 받는 데 걸리는 시간 == C 도시에서 가장 먼 노드와의 최단거리 값
		max_dist = max(max_dist, dist[i]);
	}

	cout << count - 1 << ' ' << max_dist;

	return 0;
}