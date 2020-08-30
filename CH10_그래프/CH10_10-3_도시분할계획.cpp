#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

/* 2개의 최소 신장 트리로 분할하는 문제 */
/* 최소 신장 트리를 찾은 후, 가장 비용이 큰 간선을 제거하면 해결된다. */

typedef struct edge {
	int cost;
	int a;
	int b;
}Edge;

bool cmp(const Edge& x, const Edge& y) {
	if (x.cost < y.cost) return true;
	else if (x.cost == y.cost) {
		if (x.a < y.a) return true;
		else if (x.a == y.a) {
			return x.b < y.b;
		}
	}
	return false;
}

int parent[1001];

// 사이클 판단을 위한 union & find 연산
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {

	int N, M;
	cin >> N >> M;

	int A, B, C;
	vector<Edge> info;
	Edge tmp;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		tmp.a = A; tmp.b = B; tmp.cost = C;
		info.push_back(tmp);
	}
	
	// parent 초기화
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	// cost 오름차순 정렬
	sort(info.begin(), info.end(), cmp);

	int result = 0, max_cost = 0;

	// 간선을 차례로 살피며 사이클이 아닐 경우 합집합
	for (int i = 0; i < info.size(); i++) {
		tmp = info[i];
		int cost = tmp.cost;
		int a = tmp.a;
		int b = tmp.b;

		// 사이클을 형성하지 않을 때만 합집합
		if (find(a) != find(b)) {
			unite(a, b);
			result += cost;
			max_cost = cost;
		}
	}

	cout << result - max_cost;

	return 0;
}