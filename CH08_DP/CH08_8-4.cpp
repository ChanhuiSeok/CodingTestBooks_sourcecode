#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

/* ���̳��� ���α׷����� �Ʒ� �� ���� ������ ������ �� ����� �� �ִ�. */
/* (1) ū ������ ���� ������ ���� �� �ִ� */
/* (2) ���� �������� ���� ������ �װ��� �����ϴ� ū ���������� �����ϴ� */
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