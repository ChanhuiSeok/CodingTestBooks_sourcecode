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
		// �� ���⿡�� �� �� �ִ� ���� ť�� ����ֱ�
		int y = q.front().first;
		int x = q.front().second;
		visit[y][x] = 1; // �湮ǥ�� ��
		q.pop();

		// 4���� ������
		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// �� �� �ִ� ���, ù �湮 �ÿ��� +1�� �Ѵ�.
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