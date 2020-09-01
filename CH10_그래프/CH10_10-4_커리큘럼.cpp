#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

/* ���� ������ Ȱ���� ���� */
int indegree[501];
int time[501];
int sort_result[501];
queue<int> q;
vector<int> graph[501];

int main() {

	int N, t, input, out;
	scanf("%d", &N); // ��� ���� N

	// ��� ��忡 ���� ���������� 0���� �ʱ�ȭ(�������� - �Ϸ�)
	// 1������ N�� ������ ���ǽð� �ʱ�ȭ(�������� - �Ϸ�)
	
	// ���� ���� �Է¹ޱ�
	// ù ��° ���� �� ������ ���ǽð���, �� ��°���ʹ� ����� �����
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
	
	// ���� ����
	// ���������� 0�� ��带 ť�� �ִ´�.
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	// ť�� �������� �ݺ�
	while (!q.empty()) {
		// ť���� ��带 ������.
		out = q.front();
		q.pop();

		// ť���� �����鼭 ���������� �ȴ�.
		// �� ������� �� ��庰 �����ϱ���� �ɸ��� �ð��� ���Ѵ�.

		// ���� ���� ����Ǿ� �ִ� ������ �����Ѵ�.
		for (auto i : graph[out]) {
			sort_result[i] = max(sort_result[i], sort_result[out] + time[i]);
			indegree[i] -= 1; // ���� ���� ����

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