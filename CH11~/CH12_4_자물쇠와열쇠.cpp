#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<int> result;

/* ����(4) - �ڹ���� ���� */

// lock�� board�� ����� �� [N][N]�� ��ġ�ϰ� �Ѵ�.
int board[101][101];

// key�� ȸ����Ű�� �Լ�
vector<vector<int>> rotate(vector<vector<int>> key) {
	vector<vector<int>> after;
	after.resize(key.size());

	// origin ����, after ���� �ȴ�.
	int size = key.size();
	
	for (int col = 0; col < size; col++) {
		for (int i = size - 1; i >= 0; i--) {
			int num = key[i][col];
			after[col].push_back(num);
		}
	}
	return after;
}

// lock ������ ���� 1���� Ȯ���ϴ� �Լ�
bool isAllMatch(int N) {
	for (int i = N; i < N + N; i++) {
		for (int j = N; j < N + N; j++) {
			if (board[i][j] != 1) {
				return false;
			}
		}
	}
	return true;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	int N = lock.size();

	// 1. lock�� board ���߾ӿ� ��ġ��Ų��.
	for (int i = N; i < N + N; i++) {
		for (int j = N; j < N + N; j++) {
			board[i][j] = lock[i-N][j-N];
		}
	}

	// 2. key�� �� �� �� ���ʺ��� ������ ���鼭 lock ������ ���������� Ȯ���Ѵ�.
	// �� �� lock ������ ���� 1�̸� true�� ��ȯ�� �� �ִ�.
	// ȸ�� 3�� �ϱ�
	for (int k = 0; k < 4; k++) {

		int keySize = key.size();
		int r_idx = 0, c_idx = 0;

		for (int i = 0; i < N * 2; i++) {
			for (int j = 0; j < N * 2; j++) {

				for (int row = 0; row < keySize; row++) {
					for (int col = 0; col < keySize; col++) {
						board[i + row][j + col] += key[row][col];
					}
				}

				// lock ������ ��� 1�̿��� ���
				if (isAllMatch(N)) return true;
				else {
					// �ʱ�ȭ
					for (int row = 0; row < keySize; row++) {
						for (int col = 0; col < keySize; col++) {
							board[i + row][j + col] -= key[row][col];
						}
					}
				}
			}
		}

		// 1ȸ��
		key = rotate(key);
	}

	return false;
}

int main() {
	vector<vector<int>> key = { {0,0,0},{1,0,0},{0,1,1} };
	vector<vector<int>> lock = { {1,1,1}, {1,1,0},{1,0,1} };

	solution(key, lock);

	return 0;
}