#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

/* ���ͽ�Ʈ�� */
int dist[100001];
vector<pair<int, int>> vec[100001];

void dijkstra(int start) {

	// ���� ����� �Ÿ��� 0���� ����
	dist[start] = 0;

	// �켱����ť ����
	priority_queue<pair<int, int>> pq;
	pq.push({ dist[start], start });

	while (!pq.empty()) {
		// ť���� ���� cur��, �ű⿡ ������ ���� ����� ���� ���� �Ÿ��� �����Ѵ�.
		int cur = pq.top().second;
		int distance = pq.top().first * -1;
		pq.pop();

		// �̹� ��� �ͺ��� distance�� �� ũ�� skip
		if (dist[cur] < distance) continue;

		// �� ���� ����� �ٸ� ��� ���� ��带 Ȯ���Ѵ�.
		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int nextDistance = distance + vec[cur][i].second;

			// ���� ���� ���� �ٷ� ���� �ͺ��� ª�� ���
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push({ nextDistance * -1, next });
			}
		}
	}
}

int main() {

	int N, M, C;
	// ���� ���� N, ��� ���� M, �޼����� �������� �ϴ� ���� C
	cin >> N >> M >> C;

	// 1. �Ÿ��迭 �ʱ�ȭ
	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	int X, Y, Z;
	for (int i = 0; i < M; i++) {
		cin >> X >> Y >> Z;
		vec[X].push_back({ Y,Z }); // X->Y ����ǰ� �� ������ ����ġ�� Z
	}

	dijkstra(C);

	int count = 0, max_dist = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] != INF) count += 1;
		// ���õ��� ��� �޼����� �޴� �� �ɸ��� �ð� == C ���ÿ��� ���� �� ������ �ִܰŸ� ��
		max_dist = max(max_dist, dist[i]);
	}

	cout << count - 1 << ' ' << max_dist;

	return 0;
}