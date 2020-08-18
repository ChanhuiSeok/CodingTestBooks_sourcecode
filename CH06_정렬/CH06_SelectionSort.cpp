#define _CRT_SECURE_NO_WARNINGS
#define INF 999999
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	/* selection sort */
	// 가장 작은 데이터를 맨 앞과 바꾸고, 남은 것들을 똑같은 과정 반복
	// 시간복잡도 : O(N^2)

	vector<int> arr = { 7,5,9,0,3,1,6,2,4,8 };
	int min_idx, temp;

	for (int i = 0; i < arr.size(); i++) {
		min_idx = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[min_idx] > arr[j])
				min_idx = j;
		}
		// swap
		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}

	for (int k = 0; k < arr.size(); k++)
		cout << arr[k] << " ";

}