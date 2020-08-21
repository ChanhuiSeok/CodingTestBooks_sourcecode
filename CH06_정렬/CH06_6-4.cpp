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

	/* 배열 A와 배열 B의 원소 하나를 골라 두 원소를 바꾸는 연산으로
	배열 A의 모든 원소 합이 최대가 되도록 하는 문제 */

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

	// A는 오름차순 정렬해 놓고, B는 내림차순 정렬해 놓은 뒤
	// A[i] < B[i] 일 때만 서로 원소를 교환한다.

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < K; i++) {
		if (A[i] < B[i])
			swap(A[i], B[i]);
		else
			break; // A의 원소가 B의 원소보다 크거나 같으면 교환하지 않아도 된다.
		// A가 가장 큰 합이 되어야 하기 때문
	}
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i];
	}
	cout << sum;

	return 0;

}