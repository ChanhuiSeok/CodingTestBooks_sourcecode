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
// min-heap���� ����

/* �׸��� �׷���-�������� �ؼ� */
/* �����̴� ������ ��,��,��,�� ��� �ǹǷ� ���ͽ�Ʈ��� ���� */

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

		// �Ÿ� �迭 �ʱ�ȭ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = INF;
			}
		}

		// ó���� ù ���� ����
		dist[0][0] = arr[0][0];
		pq.push({ dist[0][0], {0,0} });

		while (!pq.empty()) {
			// 1. �� ���� ����� ��ȣ�� �Ÿ��� �ϴ� ������.
			int c_row = pq.top().second.first;
			int c_col = pq.top().second.second;
			int distance = pq.top().first;

			pq.pop();

			// �̹� �ּڰ����� ó���� �ٶ��
			if (dist[c_row][c_col] < distance) continue;

			// 2. ���� ���� ����� ��� ������ ���캸�鼭 �ּڰ��� �����Ѵ�.
			for (int i = 0; i < 4; i++) {
				int ty = c_row + dy[i];
				int tx = c_col + dx[i];

				// �迭 ������ ����� ���� ���� ����
				if (ty >= 0 && ty < N && tx >= 0 && tx < N) {
					// ���� ���� �Ÿ����� ������ ���´�.
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