#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int T[16];
int P[16];
int dp[16];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t, p;
		cin >> t >> p;
		T[i] = t; P[i] = p;
	}

	int maxValue = 0;
	for (int k = N - 1; k >= 0; k--) {	
		if (T[k] + k <= N) {
			dp[k] = max(maxValue, P[k] + dp[T[k] + k]);
			maxValue = dp[k];
		}
		else {
			dp[k] = maxValue;
		}
	}

	cout << maxValue;

	return 0;
}