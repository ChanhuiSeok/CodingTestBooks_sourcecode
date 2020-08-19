#define _CRT_SECURE_NO_WARNINGS
#define INF 999999
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	/* Insertion sort */
	// 데이터를 차례로 하나씩 확인하면서, 어떤 위치에 삽입할지 정하면서 정렬
	// 시간복잡도 : O(N^2)
	// 거의 정렬된 상태의 데이터가 주어진다면,
	// 삽입 정렬이 선택 정렬보다 더 우수한 성능을 낼 수 있다.

	vector<int> arr = { 7,5,9,0,3,1,6,2,4,8 };
	int temp;

	for (int i = 1; i < arr.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
			else
				break;
		}
	}

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}

}