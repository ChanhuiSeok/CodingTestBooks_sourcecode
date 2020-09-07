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

// ��ֹ��� ����
void dfs(int cnt) {

	if (cnt == 3) {
		// ������(T)�� ��,��,��,�� ��� ���鼭
		// �л��� �ִ��� ������ �ľ�
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] == "T") {
					// �������� ��� ��,��,��,�� 4���� ��� ����

					// ������(�Ʒ����� ����)
					int T_row = i - 1;
					while (T_row >= 1) {
						if (board[T_row][j] == "O")
							break;

						if (board[T_row][j] == "S") {
							S_flag = true; // �л��� ������.
							break;
						}
						T_row -= 1;
					}
					
					// �л��� ������ �ʾ��� ���� ����
					
					if (!S_flag) {
						T_row = i + 1;
						// �Ʒ� ����(������ �Ʒ���)
						while (T_row <= N) {
							if (board[T_row][j] == "O")
								break;

							if (board[T_row][j] == "S") {
								S_flag = true; // �л��� ������.
								break;
							}
							T_row += 1;
						}
					}

					if (!S_flag) {
						// ���� ����(�����ʿ��� ��������)
						int T_col = j - 1;
						while (T_col >= 1) {
							if (board[i][T_col] == "O")
								break;

							if (board[i][T_col] == "S") {
								S_flag = true; // �л��� ������.
								break;
							}
							T_col -= 1;
						}
					}

					if (!S_flag) {
						// ������ ����(���ʿ��� ����������)
						int T_col = j + 1;
						while (T_col <= N) {
							if (board[i][T_col] == "O")
								break;

							if (board[i][T_col] == "S") {
								S_flag = true; // �л��� ������.
								break;
							}
							T_col += 1;
						}
					}

					if (S_flag == false) { // �л��� �������� ������ ���
						temp_cnt += 1;
					}
				}
			}
		}
		// �������� ���� ������ ���� ���� ������ ���ڿ� ���� ���
		if (temp_cnt == T_cnt) {
			result_flag = true;
		}

		// �ٸ� ���̽��� ���� �ʱ�ȭ
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

	// T�� ������, S�� �л�, O�� ��ֹ�

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == "T") {
				T_cnt += 1; // �������� �� ����
			}
		}
	}

	dfs(0);

	if (result_flag) cout << "YES";
	else cout << "NO";


	return 0;
}