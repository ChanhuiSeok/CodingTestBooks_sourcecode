#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define pii pair<int, int> 

/* 18405번 */

using namespace std;

int arr[201][201];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

queue<pair<pii, pii>> q;
vector<pair<pii, pii>> v;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, S, X, Y;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			// 1번부터 시작하기 위함
			if (arr[i][j] != 0) {
				v.push_back({ {arr[i][j], 0}, { i,j } });
			}
		}
	}

	sort(v.begin(), v.end());

	cin >> S >> X >> Y;
	// S초 뒤에 (X, Y) 에 존재하는 바이러스 출력

	// 정렬 후 큐에 집어넣기
	for (int i = 0; i < v.size(); i++) {
		int y = v[i].second.first;
		int x = v[i].second.second;
		int val = v[i].first.first;
		int t = v[i].first.second;

		q.push({ { val,t }, { y,x } });
	}

	while(!q.empty()) {
		// 1~K 바이러스 BFS
		int y = q.front().second.first;
		int x = q.front().second.second;
		int val = q.front().first.first;
		int t = q.front().first.second;
		q.pop();

		if (t >= S) break;

		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			if (ty >= 1 && ty <= N && tx >= 1 && tx <= N &&
				arr[ty][tx] == 0) {
				arr[ty][tx] = val;
				q.push({ {val, t + 1 }, { ty,tx }});
			}
		}
	}

	if (arr[X][Y] != 0) cout << arr[X][Y];
	else cout << 0;

	return 0;
}