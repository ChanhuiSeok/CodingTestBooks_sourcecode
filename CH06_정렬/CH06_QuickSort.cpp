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

	// ���� ����
	if (start >= end) return;

	int pivot = start; // �ǹ��� �� ó�� ������ ����
	int left = start + 1;
	int right = end;

	while (left <= right) {
		// �ǹ����� ū ������ ã�� ������ ���ʿ��� ���������� �ݺ�
		while (left <= end && arr[left] <= arr[pivot]) {
			left += 1;
		}

		// �ǹ����� ���� ������ ã�� ������ �����ʿ��� �������� �ݺ�
		while (right > start && arr[right] >= arr[pivot]) {
			right -= 1;
		}

		// left ���� right�� Ŀ���� ���(�������� ���), �ǹ����� ���� �����Ϳ� �ǹ��� �ڸ���ü
		// �̷ν� ������ �ǰ�, ���� while���� ������ ��
		if (left > right) {
			swap(arr[right], arr[pivot]);
		}
		// �������� �ʾ��� ���, ���� �����Ϳ� ū ������ ��ü
		else {
			swap(arr[right], arr[left]);
		}
	}
	// ���� ���� ���� ���� �κа� ������ �κп��� ����
	quickSort(start, right - 1);
	quickSort(right + 1, end);
}

int main() {

	/* Quick sort */
	// ���� ������(�ǹ�)�� �����ϰ� �� ���غ��� ū �����Ϳ� ���� �������� ��ġ �ٲٱ�

	quickSort(0, arr.size() - 1);

	for (int i = 0; i < arr.size(); i++) 
		cout << arr[i] << " ";
	
}