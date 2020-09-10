#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

#define INF 987654321
#define pii pair<int,int>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int dist[130][130];
int arr[130][130];
priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>>pq;
// min-heap으로 정의

/* 그림을 그래프-간선으로 해석 */
/* 움직이는 방향이 상,하,좌,우 모두 되므로 다익스트라로 진행 */

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		// 거리 배열 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = INF;
			}
		}

		// 처음은 첫 노드로 변경
		dist[0][0] = arr[0][0];
		pq.push({ dist[0][0], {0,0} });

		while (!pq.empty()) {
			// 1. 맨 앞의 노드의 번호와 거리를 일단 꺼낸다.
			int c_row = pq.top().second.first;
			int c_col = pq.top().second.second;
			int distance = pq.top().first;

			pq.pop();

			// 이미 최솟값으로 처리된 바라면
			if (dist[c_row][c_col] < distance) continue;

			// 2. 꺼낸 노드와 연결된 모든 노드들을 살펴보면서 최솟값을 갱신한다.
			for (int i = 0; i < 4; i++) {
				int ty = c_row + dy[i];
				int tx = c_col + dx[i];

				// 배열 범위에 벗어나지 않을 때만 시행
				if (ty >= 0 && ty < N && tx >= 0 && tx < N) {
					// 다음 것의 거리값을 저장해 놓는다.
					int nextDistance = distance + arr[ty][tx];

					if (dist[ty][tx] > nextDistance) {
						dist[ty][tx] = nextDistance;
						pq.push({ dist[ty][tx], {ty, tx} });
					}
				}
			}
		}
		cout << dist[N - 1][N - 1] << '\n';
	}

	return 0;
}