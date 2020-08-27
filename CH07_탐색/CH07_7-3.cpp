#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

/* 떡볶이 떡 만들기 : 이진탐색 - 파라메트릭 서치 문제 */
int N = 6;

int main() {

	int N, M, input;
	cin >> N >> M;

	vector<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}

	// 1. 정렬
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

		// 더한 값이 손님이 원하는 M보다 작으면 절단기 높이를 줄이고
		// 손님에게 줄 떡을 더 많이 잘라내기
		if (sum < M) {
			right = mid - 1;
		}

		// 더한 값이 M보다 컸을 경우 절단기 높이를 늘리고
		// 손님에게 줄 떡을 덜 잘라내기
		// H(절단기 높이) 값의 최댓값 구하는 문제
		else {
			result = mid;
			left = mid + 1;
		}
	}

	cout << result;

	return 0;
}