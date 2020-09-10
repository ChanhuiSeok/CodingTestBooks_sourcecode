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

int dist[20001];
int arr[130][130];

int N;

vector<vector<pii>> v;
priority_queue<pii, vector<pii>, greater<pii>>pq;
// min-heap으로 정의

/* 그림을 그래프-간선으로 해석 */
/* 움직이는 방향이 상,하,좌,우 모두 되므로 다익스트라로 진행 */

void dijkstra(int start) {

	dist[start] = 0;
	pq.push({ dist[start], start }); // 거리와 정점 번호

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();

		if (dist[cur] < cur_dist) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int next_dist = v[cur][i].second;

			if (dist[next] > cur_dist + next_dist) {
				dist[next] = cur_dist + next_dist;
				pq.push({ dist[next], next });
			}
		}
	}

	// dist 배열에서 최댓값을 찾기 위한 벡터 생성
	vector<int> maxV;
	int maxValue = -1;
	for (int i = 1; i <= N; i++) 
		maxValue = max(maxValue, dist[i]);
	
	for (int i = 1; i <= N; i++) {
		if (maxValue == dist[i]) 
			maxV.push_back(i);		
	}

	sort(maxV.begin(), maxV.end());
	cout << maxV[0] <<' '<< maxValue <<' '<< maxV.size() << '\n';
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	v.resize(20001);

	int M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back({ b, 1 });
		v[b].push_back({ a, 1 });
	}

	// 거리 배열 초기화
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	dijkstra(1);

	return 0;
}