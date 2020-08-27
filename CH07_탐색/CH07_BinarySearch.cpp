#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

/* ���� Ž�� - �̹� ���ĵ� �������� ��, �ſ� ������ Ž���� �� ���� */
int N = 6;

int main() {

	int arr[] = { 3,5,1,7,8,4 };
	sort(arr, arr + N);
	
	int left = 0, right = N - 1;
	int mid, target;
	
	cout << "ã������ ������ �Է� : ";
	cin >> target;

	while (left <= right) {
		mid = left + right / 2;

		if (arr[mid] == target) {
			cout << "ã�ҽ��ϴ�!\n";
			return 0;
		}

		else if (arr[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << "ã�� ���߽��ϴ�\n";
	return 0;
}