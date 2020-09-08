#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int arr[21][21];
int dp[21][21];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	int n, m;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		// ������, ������ �Ʒ�, ������ �� �� ������ �� �� ����
		for (int i = 0; i < n; i++) {
			dp[i][0] = arr[i][0]; // �ʱ�ȭ
		}

		int left_up, left, left_down;
		// 1��° ������ ����
		for (int col = 1; col < m; col++) {
			for (int row = 0; row < n; row++) {

				if (row == 0)
					left_up = 0;
				else
					left_up = dp[row - 1][col - 1];

				left = dp[row][col - 1];

				if (row == n - 1)
					left_down = 0;
				else
					left_down = dp[row + 1][col - 1];

				int maxValue = max(left_up, left);
				maxValue = max(maxValue, left_down);

				dp[row][col] = arr[row][col] + maxValue;
			}	
		}

		int maxValue = -1;
		for (int i = 0; i < n; i++) {
			maxValue = max(maxValue, dp[i][m - 1]);
		}
		cout << maxValue;

		//dp �迭 �ʱ�ȭ
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j] = 0;
			}
		}
	}


	return 0;
}