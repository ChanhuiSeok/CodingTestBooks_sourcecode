#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#define N 0 // ����
#define E 1 // ������
#define S 2 // ����
#define W 3 // ����
#define VISIT 5 // �湮

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

	// ó�� ��ġ y, x...
	// 0-����, 1-����, 2-����, 3-����
	int cur_dir = dir;
	int cy = y, cx = x;
	int cnt = 0; // �湮�� ĭ ���� ����

	int turn_cnt = 0;

	// 4���� ���⿡ ���� �ùķ��̼�
	while (1) {
		// ���� �ٶ󺸴� ������ ���ʺ��� ����
		int c_dir = turnLeft(cur_dir);

		// �� �� ���� ���
		if (valid(cy + dy[c_dir], cx + dx[c_dir])) {
			// �ٶ󺸴� ���� ����
			cur_dir = c_dir;

			// �湮 ǥ�� �� �������� ��ġ ����
			board[cy + dy[c_dir]][cx + dx[c_dir]] = VISIT;
			cy = cy + dy[c_dir];
			cx = cx + dx[c_dir];

			cnt += 1; // �湮ĭ �߰�
			turn_cnt = 0; // �� �� ��� �������״� �� �ʱ�ȭ
		}

		else {
			cur_dir = c_dir;
			turn_cnt += 1;
		}
		
		// �� ���� ��� �� �� ���� ���
		if (turn_cnt == 4) {
			// �ʱ⿡ �ٶ󺸴� ���� ���� -> �� ���� ����
			// �� ���� �������� �� ĭ �ڷ� �̵�
			int b_dir = goBack(cur_dir);

			// ���� ������ �ٴ��� ĭ�� ���, ������ ���߱�
			if (board[cy + dy[b_dir]][cx + dx[b_dir]] == 1) {
				break;
			}
			// �ٴٰ� �ƴ� ���, �����̱�
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

	// ĳ���� �ʱ� ��ġ�� ���� �Է¹ޱ�
	int iy, ix, idir;
	cin >> iy >> ix >> idir;

	// 0�� ����, 1�� �ٴ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// ó�� ��ġ �湮
	board[iy][ix] = VISIT;

	// �ùķ��̼� ����
	int result = simulate(iy, ix, idir);

	// ó�� �־��� ĭ�� +1
	cout << result + 1;

	return 0;
}