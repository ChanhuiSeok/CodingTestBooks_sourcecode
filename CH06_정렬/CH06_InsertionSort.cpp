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
	// �����͸� ���ʷ� �ϳ��� Ȯ���ϸ鼭, � ��ġ�� �������� ���ϸ鼭 ����
	// �ð����⵵ : O(N^2)
	// ���� ���ĵ� ������ �����Ͱ� �־����ٸ�,
	// ���� ������ ���� ���ĺ��� �� ����� ������ �� �� �ִ�.

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