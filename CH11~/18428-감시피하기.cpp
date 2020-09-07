#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int N;
string board[7][7];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
bool result_flag = false;
bool S_flag = false;
int temp_cnt = 0;
int T_cnt;

// 장애물의 갯수
void dfs(int cnt) {

	if (cnt == 3) {
		// 선생님(T)이 상,하,좌,우 모두 보면서
		// 학생이 있는지 없는지 파악
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] == "T") {
					// 선생님일 경우 상,하,좌,우 4방향 모두 감시

					// 위방향(아래에서 위로)
					int T_row = i - 1;
					while (T_row >= 1) {
						if (board[T_row][j] == "O")
							break;

						if (board[T_row][j] == "S") {
							S_flag = true; // 학생을 만났다.
							break;
						}
						T_row -= 1;
					}
					
					// 학생을 만나지 않았을 때만 진행
					
					if (!S_flag) {
						T_row = i + 1;
						// 아래 방향(위에서 아래로)
						while (T_row <= N) {
							if (board[T_row][j] == "O")
								break;

							if (board[T_row][j] == "S") {
								S_flag = true; // 학생을 만났다.
								break;
							}
							T_row += 1;
						}
					}

					if (!S_flag) {
						// 왼쪽 방향(오른쪽에서 왼쪽으로)
						int T_col = j - 1;
						while (T_col >= 1) {
							if (board[i][T_col] == "O")
								break;

							if (board[i][T_col] == "S") {
								S_flag = true; // 학생을 만났다.
								break;
							}
							T_col -= 1;
						}
					}

					if (!S_flag) {
						// 오른쪽 방향(왼쪽에서 오른쪽으로)
						int T_col = j + 1;
						while (T_col <= N) {
							if (board[i][T_col] == "O")
								break;

							if (board[i][T_col] == "S") {
								S_flag = true; // 학생을 만났다.
								break;
							}
							T_col += 1;
						}
					}

					if (S_flag == false) { // 학생을 감시하지 못했을 경우
						temp_cnt += 1;
					}
				}
			}
		}
		// 감시하지 못한 선생님 수가 실제 선생님 숫자와 같을 경우
		if (temp_cnt == T_cnt) {
			result_flag = true;
		}

		// 다른 케이스를 위한 초기화
		S_flag = false;
		temp_cnt = 0;

		return;
	}

	else {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] == "X") {
					board[i][j] = "O";
					dfs(cnt + 1);
					board[i][j] = "X";
				}
			}
		}
	}

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	// T는 선생님, S는 학생, O는 장애물

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == "T") {
				T_cnt += 1; // 선생님의 수 세기
			}
		}
	}

	dfs(0);

	if (result_flag) cout << "YES";
	else cout << "NO";


	return 0;
}