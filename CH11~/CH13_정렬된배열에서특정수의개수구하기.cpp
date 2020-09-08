#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

/* Ǯ�� 1 : �������� Ÿ���� ã��(logN) Ÿ�� ���ķ� ������ ����. */


int N, x;
int None = -1e9 - 1;

// ���� x�� ���ڸ� ���� �Լ�
int cnt_value(vector<int>& v, int leftVal, int rightVal) {

	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightVal);
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftVal);
	return rightIndex - leftIndex;

	// upper_bound, lower_bound�� ����Ž������ �����ϴ� STL ���� �����ϴ� �Լ��̴�.
	// upper_bound�� ���� ������ target �� "�ʰ��ϴ� ��"�� ó������ ������ ���� ���ͷ����͸� ��ȯ�ϰ�,
	// lower_bound�� ���� ������ target "�̻��� ��"�� ó������ ������ ���� ���ͷ����͸� ��ȯ�Ѵ�.
	// (arr[mid-1] < key �̸鼭 arr[mid] >= key �� �ּ��� mid)

	// (����) ������ ��� �ش� ���ͷ����Ϳ��� v.begin()�� ���� �� ��° �������� �� �� �ִ�.

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> arr;

	int input;
	cin >> N >> x;

	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}

	int cnt = cnt_value(arr, x, x);

	if (cnt == 0) {
		cout << -1;
	}
	else {
		cout << cnt;
	}

	return 0;
}