#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

/* 위상 정렬을 활용한 문제 */
int indegree[501];
int time[501];
int sort_result[501];
queue<int> q;
vector<int> graph[501];

int main() {

	int N, t, input, out;
	scanf("%d", &N); // 노드 개수 N

	// 모든 노드에 대한 진입차수를 0으로 초기화(전역변수 - 완료)
	// 1번부터 N번 까지의 강의시간 초기화(전역변수 - 완료)
	
	// 간선 정보 입력받기
	// 첫 번째 수는 그 강의의 강의시간을, 두 번째부터는 연결된 노드임
	for (int i = 1; i <= N; i++) {
		scanf("%d", &t);
		time[i] = t;

		while (1) {
			scanf("%d", &input);
			if (input == -1) break;
			else {
				indegree[i] += 1;
				graph[input].push_back(i);
			}
		}
	}

	copy(time + 1, time + N + 1, sort_result + 1);
	
	// 위상 정렬
	// 진입차수가 0인 노드를 큐에 넣는다.
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	// 큐가 빌때까지 반복
	while (!q.empty()) {
		// 큐에서 노드를 꺼낸다.
		out = q.front();
		q.pop();

		// 큐에서 꺼내면서 위상정렬이 된다.
		// 그 순서대로 각 노드별 수강하기까지 걸리는 시간을 구한다.

		// 꺼낸 노드와 연결되어 있는 간선을 제거한다.
		for (auto i : graph[out]) {
			sort_result[i] = max(sort_result[i], sort_result[out] + time[i]);
			indegree[i] -= 1; // 진입 차수 감소

			if (indegree[i] == 0) {
				q.push(i);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", sort_result[i]);
	}

	return 0;
}