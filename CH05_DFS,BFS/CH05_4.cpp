#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int arr[1001][1001];
int visit[1001][1001];

int N, M;
int cnt;

queue<pair<int, int>> q;

bool valid(int y, int x) {

	if (y <= 0 || x <= 0 || y > N || x > M || visit[y][x] == 1 || arr[y][x] == 0) {
		return false;
	}
	return true;
}

void bfs() {

	q.push({ 1,1 });

	while (!q.empty()) {
		// 네 방향에서 갈 수 있는 곳을 큐에 집어넣기
		int y = q.front().first;
		int x = q.front().second;
		visit[y][x] = 1; // 방문표시 후
		q.pop();

		// 4방향 가보기
		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// 갈 수 있는 경우, 첫 방문 시에만 +1을 한다.
			if (valid(ty, tx)) {
				arr[ty][tx] = arr[y][x] + 1;
				q.push({ ty,tx });
			}
		}
	}

}


int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	bfs();

	cout << arr[N][M];

	return 0;
}