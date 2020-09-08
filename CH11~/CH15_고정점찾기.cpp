#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

#define None -1e9-1

using namespace std;

int binary_search(vector<int>&arr, int left, int right) {

	if (left > right) {
		return None;
	}

	int mid = (left + right) / 2;

	if (arr[mid] == mid) return mid; // 고정점일 경우 반환

	else if (arr[mid] > mid) {
		return binary_search(arr, left, mid - 1);
	}
	else {
		return binary_search(arr, mid + 1, right);
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> arr;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
	}

	int res = binary_search(arr, 0, N - 1);

	if (res == None) cout << -1;
	else cout << res;

	return 0;
}