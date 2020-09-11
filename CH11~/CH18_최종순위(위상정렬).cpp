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

/* 순위 관련, 그리고 그 순위 유지나 그런 느낌의 문제는 위상 정렬 떠올려 보기 */

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
		cin >> n; // 팀의 수 n
		
		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			last_rank.push_back(input);
		}
		// 작년에 i등을 한 팀부터 차례대로 last_rank에 담김

		cin >> m; // 작년과 올해 비교해 상대적인 등수가 바뀐 쌍 수 m
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			changed.push_back({ a,b });
		}

		//indegree 배열 초기화
		for (int i = 1; i <= n; i++) 
			indegree[i] = 0;
		
		// 그래프 형성
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				// i번째 노드 ---> j번째 노드
				graph[last_rank[i]][last_rank[j]] = 1;

				// j번째 노드의 진입차수 1 증가
				indegree[last_rank[j]] += 1;
			}
		}

		// changed에 맞게 순서 변경
		for (int i = 0; i < m; i++) {
			int a, b;
			a = changed[i].first;
			b = changed[i].second;

			// a--->b 가 기존이었으면
			if (graph[a][b] == 1) {
				graph[b][a] = 1;
				graph[a][b] = 0;
				indegree[b] -= 1;
				indegree[a] += 1;
			}

			// b--->a 가 기존이었으면
			else if (graph[b][a] == 1) {
				graph[a][b] = 1;
				graph[b][a] = 0;
				indegree[a] -= 1;
				indegree[b] += 1;
			}
		}

		// 위상 정렬 진행해 보기
		// 진입 차수가 0인 노드를 큐에 넣는다.
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		// 순위를 정할 수 없는 경우(아예 결과 못 내는 경우) : cycle일 때
		// 순위(답)가 여러 개 나올 수 있는 경우 = 확실한 순위를 찾을 수 없을 때 : 큐에 2개 이상 노드가 있을 때

		bool onlyOneFlag = true; // 오직 답이 1개인지 나타내는 플래그
		bool hasCycleFlag = false; // cycle 가지는 유무 나타내는 플래그

		vector<int> result;

		int input, out;
		for(int i = 0; i<n; i++){

			// 큐에 원소가 2개 이상일 경우, 여러 갈래 방향이(같은 우선순위가) 한 번에 들어갔었다는 의미임
			// 그러므로 답이 여러 개가 될 수 있음 == 확실한 답을 낼 수 없음
			if (q.size() >= 2) {
				onlyOneFlag = false;
				break;
			}

			// 원소 개수만큼 모두 돌아야 큐가 비어야 하는데 그 전부터 큐가 빌 경우
			if (q.empty()) {
				hasCycleFlag = true;
				break;
			}

			out = q.front();
			q.pop();
			result.push_back(out);

			// out ---> i 일 경우
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

		// graph 초기화
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = 0;
			}
		}

	}

	return 0;
}