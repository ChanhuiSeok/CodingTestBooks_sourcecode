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
int dp[30001];

int main() {

	// 1로 만들기
	
	int x;
	cin >> x;

	// 연산의 종류는 4가지
	// 1. x가 5로 나누어떨어지면 5로 나눈다
	// 2. x가 3으로 나누어떨어지면 3으로 나눈다
	// 3. x가 2로 나누어떨어지면 2로 나눈다
	// 4. x에서 1을 뺀다.
	
	for (int i = 2; i <= x; i++) {

		// dp 테이블에는 항상 최소의 연산 횟수가 담긴다.
		// 예 : X=3 일 경우, (X=2일 때 1로 만드는 최소 연산 횟수) + (1을 빼는 연산 1번 호출)
		// 처음 : 
		dp[i] = dp[i - 1] + 1;

		// 만약 i가 2로 나누어떨어질 경우
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 5 == 0) {
			dp[i] = min(dp[i], dp[i / 5] + 1);
		}
	}

	cout << dp[x];

	return 0;
}