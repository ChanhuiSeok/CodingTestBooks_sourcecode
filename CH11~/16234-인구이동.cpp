#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int N;
int board[51][51];
int visit[51][51];
int area[51][51]; // ���� ��ȣ

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

// ���� ��ǥ��, ���� ��ȣ�� ����
queue<pair<int, int>>q;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int L, R;

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	
	int moveCnt = 0;
	bool moveFlag;
	vector<vector<pair<int, int>>> v;

	while (1) {
		v.resize(2501);
		int num = 1;
		moveFlag = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (visit[i][j] == 0) {
					q.push({ i, j });

					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();

						area[y][x] = num;

						// 4���� �̵�
						for (int k = 0; k < 4; k++) {
							int ty = y + dy[k];
							int tx = x + dx[k];

							// �ּ� ���� ����
							if (tx >= 0 && tx < N && ty >= 0 && ty < N &&
								!visit[ty][tx]) {

								// �α� ���̰� ���ǿ� ���� ���� ť�� �ִ´�.
								if (abs(board[y][x] - board[ty][tx]) >= L &&
									abs(board[y][x] - board[ty][tx]) <= R) {
									visit[ty][tx] = 1;
									q.push({ ty,tx });
									area[ty][tx] = num;

									moveFlag = true;
								}
							}
						}// end for
					} //end while

					num += 1;
				}
			}
		}

		// �������� �ʾ����� break
		if (moveFlag == false) break;

		// ���� ���ճ��� ��������, �� ���� ������ ��´�.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				v[area[i][j]].push_back({ i,j });
			}
		}

		// ���տ� ���ϴ� ���� ��� ���ڸ� �����Ѵ�.
		for (int i = 0; i < v.size(); i++) {
			int sum = 0;

			for (int j = 0; j < v[i].size(); j++) {
				int y = v[i][j].first;
				int x = v[i][j].second;
				sum += board[y][x];
			}
			for (int j = 0; j < v[i].size(); j++) {
				int y = v[i][j].first;
				int x = v[i][j].second;
				board[y][x] = sum / v[i].size();
			}
		}

		// 1ȸ �̵� �Ϸ�
		v.clear();
		moveCnt += 1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				area[i][j] = 0;
				visit[i][j] = 0;
			}
		}
	}

	cout << moveCnt;

	return 0;
}