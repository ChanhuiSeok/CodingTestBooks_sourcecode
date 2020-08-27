#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

/* 이진 탐색 - 이미 정렬된 데이터일 때, 매우 빠르게 탐색할 수 있음 */
int N = 6;

int main() {

	int arr[] = { 3,5,1,7,8,4 };
	sort(arr, arr + N);
	
	int left = 0, right = N - 1;
	int mid, target;
	
	cout << "찾으려는 데이터 입력 : ";
	cin >> target;

	while (left <= right) {
		mid = left + right / 2;

		if (arr[mid] == target) {
			cout << "찾았습니다!\n";
			return 0;
		}

		else if (arr[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << "찾지 못했습니다\n";
	return 0;
}