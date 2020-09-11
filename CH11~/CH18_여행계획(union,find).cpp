#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int parent[501];
int arr[501][501];

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

	ios::sync_with_stdio(0);
	cin.tie(0);

	// 부모 배열 초기화
	int N, M;
	cin >> N>> M;
	
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				unite(i, j);
			}
		}
	}

	// 여행 계획 입력받고, 모두 루트가 동일한지 확인해 주면 된다.
	vector<int> plan;
	for (int k = 0; k < M; k++) {
		int a;
		cin >> a;
		plan.push_back(a);
	}

	bool flag = true;
	for (int k = 0; k < M - 1; k++) {
		if (find(plan[k]) != find(plan[k + 1])) {
			flag = false;
		}
	}
	if (flag) cout << "YES";
	else cout << "NO";

	return 0;
}