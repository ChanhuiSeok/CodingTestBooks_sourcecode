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

/* 구현(4) - 자물쇠와 열쇠 */

// lock은 board의 정가운데 즉 [N][N]에 위치하게 한다.
int board[101][101];

// key를 회전시키는 함수
vector<vector<int>> rotate(vector<vector<int>> key) {
	vector<vector<int>> after;
	after.resize(key.size());

	// origin 행이, after 열이 된다.
	int size = key.size();
	
	for (int col = 0; col < size; col++) {
		for (int i = size - 1; i >= 0; i--) {
			int num = key[i][col];
			after[col].push_back(num);
		}
	}
	return after;
}

// lock 영역이 전부 1인지 확인하는 함수
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

	// 1. lock을 board 정중앙에 위치시킨다.
	for (int i = N; i < N + N; i++) {
		for (int j = N; j < N + N; j++) {
			board[i][j] = lock[i-N][j-N];
		}
	}

	// 2. key를 맨 위 맨 왼쪽부터 움직여 가면서 lock 영역을 지속적으로 확인한다.
	// 이 때 lock 영역이 전부 1이면 true를 반환할 수 있다.
	// 회전 3번 하기
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

				// lock 영역이 모두 1이였을 경우
				if (isAllMatch(N)) return true;
				else {
					// 초기화
					for (int row = 0; row < keySize; row++) {
						for (int col = 0; col < keySize; col++) {
							board[i + row][j + col] -= key[row][col];
						}
					}
				}
			}
		}

		// 1회전
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