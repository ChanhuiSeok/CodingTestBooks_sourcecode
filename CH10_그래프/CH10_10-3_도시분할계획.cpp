#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

/* 2���� �ּ� ���� Ʈ���� �����ϴ� ���� */
/* �ּ� ���� Ʈ���� ã�� ��, ���� ����� ū ������ �����ϸ� �ذ�ȴ�. */

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

// ����Ŭ �Ǵ��� ���� union & find ����
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
	
	// parent �ʱ�ȭ
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	// cost �������� ����
	sort(info.begin(), info.end(), cmp);

	int result = 0, max_cost = 0;

	// ������ ���ʷ� ���Ǹ� ����Ŭ�� �ƴ� ��� ������
	for (int i = 0; i < info.size(); i++) {
		tmp = info[i];
		int cost = tmp.cost;
		int a = tmp.a;
		int b = tmp.b;

		// ����Ŭ�� �������� ���� ���� ������
		if (find(a) != find(b)) {
			unite(a, b);
			result += cost;
			max_cost = cost;
		}
	}

	cout << result - max_cost;

	return 0;
}