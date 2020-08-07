#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#define N 0 // 위쪽
#define E 1 // 오른쪽
#define S 2 // 남쪽
#define W 3 // 서쪽
#define VISIT 5 // 방문

using namespace std;
int board[51][51];
int n, m;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int turnLeft(int dir) {
	if (dir == N) return W;
	else if (dir == E) return N;
	else if (dir == W) return S;
	else return E;
}

int goBack(int dir) {
	if (dir == N) return S;
	else if (dir == E) return W;
	else if (dir == S) return N;
	else if (dir == W) return E;
}

bool valid(int y, int x) {
	if (y < 0 || x < 0 || y >= m || x >= n || board[y][x] == 1 || board[y][x] == VISIT) {
		return false;
	}
	return true;
}

int simulate(int y, int x, int dir) {

	// 처음 위치 y, x...
	// 0-북쪽, 1-동쪽, 2-남쪽, 3-서쪽
	int cur_dir = dir;
	int cy = y, cx = x;
	int cnt = 0; // 방문한 칸 세는 변수

	int turn_cnt = 0;

	// 4가지 방향에 대해 시뮬레이션
	while (1) {
		// 현재 바라보는 방향의 왼쪽부터 시작
		int c_dir = turnLeft(cur_dir);

		// 갈 수 있을 경우
		if (valid(cy + dy[c_dir], cx + dx[c_dir])) {
			// 바라보는 방향 변경
			cur_dir = c_dir;

			// 방문 표시 후 그쪽으로 위치 변경
			board[cy + dy[c_dir]][cx + dx[c_dir]] = VISIT;
			cy = cy + dy[c_dir];
			cx = cx + dx[c_dir];

			cnt += 1; // 방문칸 추가
			turn_cnt = 0; // 갈 수 없어서 증가시켰던 값 초기화
		}

		else {
			cur_dir = c_dir;
			turn_cnt += 1;
		}
		
		// 네 방향 모두 갈 수 없을 경우
		if (turn_cnt == 4) {
			// 초기에 바라보던 방향 유지 -> 값 대입 없음
			// 그 방향 기준으로 한 칸 뒤로 이동
			int b_dir = goBack(cur_dir);

			// 뒤쪽 방향이 바다인 칸일 경우, 움직임 멈추기
			if (board[cy + dy[b_dir]][cx + dx[b_dir]] == 1) {
				break;
			}
			// 바다가 아닐 경우, 움직이기
			else {
				cy = cy + dy[b_dir];
				cx = cx + dx[b_dir];
			}
			turn_cnt = 0;
		}
	}

	return cnt;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	// 캐릭터 초기 위치와 방향 입력받기
	int iy, ix, idir;
	cin >> iy >> ix >> idir;

	// 0은 육지, 1은 바다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 처음 위치 방문
	board[iy][ix] = VISIT;

	// 시뮬레이션 시작
	int result = simulate(iy, ix, idir);

	// 처음 있었던 칸도 +1
	cout << result + 1;

	return 0;
}