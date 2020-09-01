#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int parent[1001];

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

	// √ ±‚»≠
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	int oper, a, b;
	int pa, pb;

	for (int i = 0; i < M; i++) {
		cin >> oper >> a >> b;
		if (oper == 0) // unite
			unite(a, b);
		else if (oper == 1) // find
		{	
			pa = find(a);
			pb = find(b);
			if (pa == pb) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}