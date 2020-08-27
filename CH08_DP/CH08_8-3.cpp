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

	int N, input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i] = input;
	}

	dp[0] = arr[0];
	dp[1] = max(arr[0], arr[1]);

	for (int i = 2; i < N; i++) {
		// �ٷ� ���� â�� �аų�, ���� â�� �а� ���� â�� �� �� �߿���
		// �� ū ���� �ִ´�.
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
	}

	cout << dp[N - 1];

	return 0;
}