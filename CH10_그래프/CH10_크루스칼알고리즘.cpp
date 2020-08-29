#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

/* 최소 신장 트리 구하기 - 크루스칼 알고리즘 */
/* [1] 간선 데이터를 비용(가중치)에 따라 오름차순으로 정렬
-> [2] 간선을 하나씩 모두 확인하면서, 간선이 사이클을 발생하는지 확인
->-> [2-1]. 사이클 확인방법은 a, b 노드를 합집합하기 전 두 노드의 부모가 같은지
			확인하면 된다. 사이클이 발생하지 않으면 합집합한다.
*/
typedef struct edge{
	int cost;
	int a;
	int b;
}Edge;

int parent[1001];
vector<Edge> info;

bool compare(const Edge& a, const Edge& b) {
	if (a.cost < b.cost) return true;
	else if (a.cost == b.cost) {
		if (a.a < b.a) return true;
		else if (a.a == b.a) {
			if (a.b < b.b) return true;
		}
	}
	return false;
}

// 사이클 판단을 위한 union, find
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {

	int v, e; // 노드 개수, 간선 개수
	cin >> v >> e;

	// 부모를 자기 자신으로 초기화
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	int a, b, w, costs = 0;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> w;
		Edge temp;
		temp.a = a; temp.b = b; temp.cost = w;
		info.push_back(temp);
	}

	// 거리값을 기준으로 오름차순 정렬
	sort(info.begin(), info.end(), compare);

	// 간선을 하나씩 확인, 사이클이 발생하지 않는 경우만 집합에 포함
	for (int i = 0; i < info.size(); i++) {

		Edge temp = info[i];
		int cost = temp.cost;
		int a = temp.a;
		int b = temp.b;

		// 부모가 다를 때만 집합에 포함
		if (find(a) != find(b)) {
			unite(a, b);
			costs += cost;
		}
	}

	cout << costs;

	return 0;
}