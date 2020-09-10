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
// min-heap���� ����

/* �׸��� �׷���-�������� �ؼ� */
/* �����̴� ������ ��,��,��,�� ��� �ǹǷ� ���ͽ�Ʈ��� ���� */

void dijkstra(int start) {

	dist[start] = 0;
	pq.push({ dist[start], start }); // �Ÿ��� ���� ��ȣ

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

	// dist �迭���� �ִ��� ã�� ���� ���� ����
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

	// �Ÿ� �迭 �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	dijkstra(1);

	return 0;
}