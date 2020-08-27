#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

/* 다이나믹 프로그래밍은 아래 두 가지 조건을 만족할 때 사용할 수 있다. */
/* (1) 큰 문제를 작은 문제로 나눌 수 있다 */
/* (2) 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다 */
int dp[1001];
int arr[1001];

int main() {

	int N, input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i] = input;
	}

	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[1]);

	for (int i = 2; i < N; i++) {
		// 바로 이전 창고를 털거나, 전전 창고를 털고 지금 창고를 턴 것 중에서
		// 더 큰 것을 넣는다.
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
	}

	cout << dp[N - 1];

	return 0;
}