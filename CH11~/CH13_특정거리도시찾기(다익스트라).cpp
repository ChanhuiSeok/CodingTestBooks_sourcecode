#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

/* 18352�� - ���ͽ�Ʈ�� Ǯ�� */

#define INF 987654321
#define pii pair<int, int>

using namespace std;

int dist[300001];

vector<vector<pii>> path;
priority_queue<pii, vector<pii>, greater<pii>> pq; //min-heap

void dijkstra(int v) {

	// ����
	dist[v] = 0;
	pq.push({ dist[v], v });

	while (!pq.empty()) {
		int distance = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		// ť���� ���� �� ���� �Ͱ� ����� ��� ��带 Ȯ���ϸ鼭 �Ÿ��� ������Ʈ
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
	// ���ð���, ���ΰ���, �Ÿ�����, ��ߵ��ù�ȣ

	cin >> N >> M >> K >> X;

	// �Ÿ��迭 �ʱ�ȭ
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