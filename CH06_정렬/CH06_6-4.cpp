#define _CRT_SECURE_NO_WARNINGS
/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <ctime>

using namespace std;

int main() {

	/* �迭 A�� �迭 B�� ���� �ϳ��� ��� �� ���Ҹ� �ٲٴ� ��������
	�迭 A�� ��� ���� ���� �ִ밡 �ǵ��� �ϴ� ���� */

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	int input;
	cin >> N >> K;

	vector<int> A, B;

	for (int i = 0; i < N; i++) {
		cin >> input;
		A.push_back(input);
	}
	for (int i = 0; i < N; i++) {
		cin >> input;
		B.push_back(input);
	}

	// A�� �������� ������ ����, B�� �������� ������ ���� ��
	// A[i] < B[i] �� ���� ���� ���Ҹ� ��ȯ�Ѵ�.

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < K; i++) {
		if (A[i] < B[i])
			swap(A[i], B[i]);
		else
			break; // A�� ���Ұ� B�� ���Һ��� ũ�ų� ������ ��ȯ���� �ʾƵ� �ȴ�.
		// A�� ���� ū ���� �Ǿ�� �ϱ� ����
	}
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i];
	}
	cout << sum;

	return 0;

}