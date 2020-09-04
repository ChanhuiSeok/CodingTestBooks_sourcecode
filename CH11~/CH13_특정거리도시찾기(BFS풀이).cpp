#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

/* 18352번 - BFS 풀이 */

using namespace std;

vector<vector<int>> path;
queue<pair<int, int>> q;
int visit[300001];
int distArr[300001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, X, a, b;
	// 도시개수, 도로개수, 거리정보, 출발도시번호

	cin >> N >> M >> K >> X;

	path.resize(N + 1);

	for (int i = 0; i < M; i++) {
		// a to b
		cin >> a >> b;
		path[a].push_back(b);
	}

	int g_dist = 0;
	q.push({ X,0 }); // 시작

	while (!q.empty()) {
		int node = q.front().first;
		int dist = q.front().second;
		q.pop();
		for (int i = 0; i < path[node].size(); i++) {
			if (visit[path[node][i]] == 0) {
				visit[path[node][i]] = 1;
				q.push({ path[node][i], dist + 1 });
				distArr[path[node][i]] = dist + 1;
			}
		}
	}

	bool flag = false;
	for (int i = 1; i <= N; i++) {
		if (distArr[i] == K) {
			cout << i << '\n';
			flag = true;
		}
	}

	if (!flag) cout << -1;

	return 0;
}