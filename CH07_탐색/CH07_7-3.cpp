#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

/* ������ �� ����� : ����Ž�� - �Ķ��Ʈ�� ��ġ ���� */
int N = 6;

int main() {

	int N, M, input;
	cin >> N >> M;

	vector<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}

	// 1. ����
	sort(arr.begin(), arr.end());

	int left, right, mid, sum;
	left = 0, right = arr[arr.size() - 1];

	int result;

	while (left <= right) {
		sum = 0;
		mid = (left + right) / 2;

		for (auto x : arr) {
			if (x > mid)
				sum += x - mid;
		}

		// ���� ���� �մ��� ���ϴ� M���� ������ ���ܱ� ���̸� ���̰�
		// �մԿ��� �� ���� �� ���� �߶󳻱�
		if (sum < M) {
			right = mid - 1;
		}

		// ���� ���� M���� ���� ��� ���ܱ� ���̸� �ø���
		// �մԿ��� �� ���� �� �߶󳻱�
		// H(���ܱ� ����) ���� �ִ� ���ϴ� ����
		else {
			result = mid;
			left = mid + 1;
		}
	}

	cout << result;

	return 0;
}