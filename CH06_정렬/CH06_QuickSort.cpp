#define _CRT_SECURE_NO_WARNINGS
#define INF 999999
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr = { 7,5,9,0,3,1,6,2,4,8 };

void quickSort(int start, int end) {

	// 종료 조건
	if (start >= end) return;

	int pivot = start; // 피벗을 맨 처음 것으로 설정
	int left = start + 1;
	int right = end;

	while (left <= right) {
		// 피벗보다 큰 데이터 찾을 때까지 왼쪽에서 오른쪽으로 반복
		while (left <= end && arr[left] <= arr[pivot]) {
			left += 1;
		}

		// 피벗보다 작은 데이터 찾을 때까지 오른쪽에서 왼쪽으로 반복
		while (right > start && arr[right] >= arr[pivot]) {
			right -= 1;
		}

		// left 보다 right가 커졌을 경우(엇갈렸을 경우), 피벗보다 작은 데이터와 피벗을 자리교체
		// 이로써 분할이 되고, 이후 while문을 나가게 됨
		if (left > right) {
			swap(arr[right], arr[pivot]);
		}
		// 엇갈리지 않았을 경우, 작은 데이터와 큰 데이터 교체
		else {
			swap(arr[right], arr[left]);
		}
	}
	// 분할 이후 각각 왼쪽 부분과 오른쪽 부분에서 정렬
	quickSort(start, right - 1);
	quickSort(right + 1, end);
}

int main() {

	/* Quick sort */
	// 기준 데이터(피벗)를 설정하고 그 기준보다 큰 데이터와 작은 데이터의 위치 바꾸기

	quickSort(0, arr.size() - 1);

	for (int i = 0; i < arr.size(); i++) 
		cout << arr[i] << " ";
	
}