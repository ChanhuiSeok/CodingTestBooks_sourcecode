#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

/* �ּ� ���� Ʈ�� ���ϱ� - ũ�罺Į �˰��� */
/* [1] ���� �����͸� ���(����ġ)�� ���� ������������ ����
-> [2] ������ �ϳ��� ��� Ȯ���ϸ鼭, ������ ����Ŭ�� �߻��ϴ��� Ȯ��
->-> [2-1]. ����Ŭ Ȯ�ι���� a, b ��带 �������ϱ� �� �� ����� �θ� ������
			Ȯ���ϸ� �ȴ�. ����Ŭ�� �߻����� ������ �������Ѵ�.
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

// ����Ŭ �Ǵ��� ���� union, find
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

	int v, e; // ��� ����, ���� ����
	cin >> v >> e;

	// �θ� �ڱ� �ڽ����� �ʱ�ȭ
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

	// �Ÿ����� �������� �������� ����
	sort(info.begin(), info.end(), compare);

	// ������ �ϳ��� Ȯ��, ����Ŭ�� �߻����� �ʴ� ��츸 ���տ� ����
	for (int i = 0; i < info.size(); i++) {

		Edge temp = info[i];
		int cost = temp.cost;
		int a = temp.a;
		int b = temp.b;

		// �θ� �ٸ� ���� ���տ� ����
		if (find(a) != find(b)) {
			unite(a, b);
			costs += cost;
		}
	}

	cout << costs;

	return 0;
}