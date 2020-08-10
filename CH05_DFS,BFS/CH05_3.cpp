#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int arr[1001][1001];
int visit[1001][1001];

int N, M;
int cnt;

bool valid(int y, int x) {

	if (y < 0 || x < 0 || y >= N || x >= M || visit[y][x] == 1 || arr[y][x] == 1) {
		return false;
	}
	return true;
}

void dfs(int y, int x) {

	// 방문 표시
	visit[y][x] = 1;
	
	// 4방향 가보기
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];

		// 갈 수 있는 경우
		if (valid(ty, tx)) {
			visit[ty][tx] = 1; // 방문표시 후
			dfs(ty, tx);
		}
	}
}


int main() {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0 && visit[i][j] == 0) {
				dfs(i, j);
				cnt += 1;
			}
		}
	}	

	printf("%d", cnt);

	return 0;
}