#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

#define pii pair<int, int>

int indegree[501];
int graph[501][501];

/* ���� ����, �׸��� �� ���� ������ �׷� ������ ������ ���� ���� ���÷� ���� */

using namespace std;
int main() {

	queue<int> q;

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, m;
		vector<int> last_rank;
		vector<pair<int, int>> changed;
		cin >> n; // ���� �� n
		
		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			last_rank.push_back(input);
		}
		// �۳⿡ i���� �� ������ ���ʴ�� last_rank�� ���

		cin >> m; // �۳�� ���� ���� ������� ����� �ٲ� �� �� m
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			changed.push_back({ a,b });
		}

		//indegree �迭 �ʱ�ȭ
		for (int i = 1; i <= n; i++) 
			indegree[i] = 0;
		
		// �׷��� ����
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				// i��° ��� ---> j��° ���
				graph[last_rank[i]][last_rank[j]] = 1;

				// j��° ����� �������� 1 ����
				indegree[last_rank[j]] += 1;
			}
		}

		// changed�� �°� ���� ����
		for (int i = 0; i < m; i++) {
			int a, b;
			a = changed[i].first;
			b = changed[i].second;

			// a--->b �� �����̾�����
			if (graph[a][b] == 1) {
				graph[b][a] = 1;
				graph[a][b] = 0;
				indegree[b] -= 1;
				indegree[a] += 1;
			}

			// b--->a �� �����̾�����
			else if (graph[b][a] == 1) {
				graph[a][b] = 1;
				graph[b][a] = 0;
				indegree[a] -= 1;
				indegree[b] += 1;
			}
		}

		// ���� ���� ������ ����
		// ���� ������ 0�� ��带 ť�� �ִ´�.
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		// ������ ���� �� ���� ���(�ƿ� ��� �� ���� ���) : cycle�� ��
		// ����(��)�� ���� �� ���� �� �ִ� ��� = Ȯ���� ������ ã�� �� ���� �� : ť�� 2�� �̻� ��尡 ���� ��

		bool onlyOneFlag = true; // ���� ���� 1������ ��Ÿ���� �÷���
		bool hasCycleFlag = false; // cycle ������ ���� ��Ÿ���� �÷���

		vector<int> result;

		int input, out;
		for(int i = 0; i<n; i++){

			// ť�� ���Ұ� 2�� �̻��� ���, ���� ���� ������(���� �켱������) �� ���� �����ٴ� �ǹ���
			// �׷��Ƿ� ���� ���� ���� �� �� ���� == Ȯ���� ���� �� �� ����
			if (q.size() >= 2) {
				onlyOneFlag = false;
				break;
			}

			// ���� ������ŭ ��� ���ƾ� ť�� ���� �ϴµ� �� ������ ť�� �� ���
			if (q.empty()) {
				hasCycleFlag = true;
				break;
			}

			out = q.front();
			q.pop();
			result.push_back(out);

			// out ---> i �� ���
			for (int i = 1; i <= n; i++) {
				if (graph[out][i] == 1) {
					indegree[i] -= 1;
					if (indegree[i] == 0) q.push(i);
				}
			}
		}	

		if (!onlyOneFlag) cout << "?\n";
		else if (hasCycleFlag) cout << "IMPOSSIBLE\n";
		else {
			for (int i = 0; i < result.size(); i++) {
				cout << result[i] << " ";
			}
			cout << '\n';
		}

		// graph �ʱ�ȭ
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = 0;
			}
		}

	}

	return 0;
}