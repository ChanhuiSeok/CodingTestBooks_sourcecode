#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

#define INF 1000001

using namespace std;

int dp[101]; // (index)원을 만드는 데 필요한 최소 화폐 갯수

int main() {

	int N, M;
	cin >> N >> M;

	vector<int> money;
	int input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		money.push_back(input);
	}

	dp[0] = 0;
	for (int i = 1; i <= M; i++) 
		dp[i] = INF;
	
	for (int i = 0; i < N; i++) {
		for (int j = money[i]; j <= M; j++) {
			dp[j] = min(dp[j], dp[j - money[i]] + 1);
		}
	}

	if (dp[M] != INF) {
		cout << dp[M];
	}
	else
		cout << "-1";

	return 0;
}