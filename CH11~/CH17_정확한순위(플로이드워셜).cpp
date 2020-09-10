#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

#define INF 987654321

using namespace std;

int info[501][501];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	// 배열 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j)
				info[i][j] = INF;
			else if (i == j)
				info[i][j] = 0;
		}
	}

	// 길을 표시	

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		info[a][b] = 1;
	}

	// 플루이드-워셜 진행
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				info[i][j] = min(info[i][j], info[i][k] + info[k][j]);
			}
		}
	}

	int res_cnt = 0;
	int temp_cnt = 0;

	// 1번 학생부터 도달 가능한지 확인
	for (int i = 1; i <= N; i++) {
		temp_cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (info[i][j] != INF || info[j][i] != INF) {
				temp_cnt += 1;
			}
		}
		if (temp_cnt == N)
			res_cnt += 1;
	}

	cout << res_cnt;

	return 0;
}