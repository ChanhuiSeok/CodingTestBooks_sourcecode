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
	// ���� ���� �����͸� �� �հ� �ٲٰ�, ���� �͵��� �Ȱ��� ���� �ݺ�
	// �ð����⵵ : O(N^2)

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