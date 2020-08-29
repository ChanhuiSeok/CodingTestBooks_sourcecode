#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

#define INF 987654321

using namespace std;

/* 플로이드-워셜 */
/* 1번 노드-> K번 노드-> X번 노드로 가는 최단 경로가 있는가? */

int dist[101][101];

int main() {

	int N, M;
	cin >> N >> M;

	// 거리 배열 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = INF;
			if (i == j) dist[i][j] = 0;
		}
	}

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	int K, X;
	cin >> X >> K;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int result = dist[1][K] + dist[K][X];
	
	if (result >= INF) cout << "-1";
	else cout << result;

	return 0;
}