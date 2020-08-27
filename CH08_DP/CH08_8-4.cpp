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

	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + (dp[i - 2] * 2)) % 796796;
	}

	cout << dp[N];

	return 0;
}