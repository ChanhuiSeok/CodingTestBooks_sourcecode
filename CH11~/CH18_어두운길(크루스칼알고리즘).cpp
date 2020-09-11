#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

#define pii pair<int, int>

using namespace std;

vector<pair<int, pii>> v;
int parent[200001];

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

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({ z,{x,y} });
	}
	
	// 정렬(오름차순)
	sort(v.begin(), v.end());

	// parent 배열 초기화
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	// 처음부터 살펴본다.
	int non_sum = 0;
	int total = 0;
	int avail_sum = 0;
	for (int i = 0; i < v.size(); i++) {
		int a = v[i].second.first;
		int b = v[i].second.second;
		int z = v[i].first;

		total += z;

		a = find(a);
		b = find(b);

		if (a != b) {
			unite(a, b);
			avail_sum += z;
		}
	}

	cout << total - avail_sum;

	return 0;
}