#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

/* 풀이 1 : 수열에서 타겟을 찾고(logN) 타겟 전후로 갯수를 센다. */


int N, x;
int None = -1e9 - 1;

// 값이 x인 숫자를 세는 함수
int cnt_value(vector<int>& v, int leftVal, int rightVal) {

	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightVal);
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftVal);
	return rightIndex - leftIndex;

	// upper_bound, lower_bound는 이진탐색으로 동작하는 STL 에서 제공하는 함수이다.
	// upper_bound는 수열 내에서 target 을 "초과하는 값"이 처음으로 나오는 곳의 이터레이터를 반환하고,
	// lower_bound는 수열 내에서 target "이상인 값"이 처음으로 나오는 곳의 이터레이터를 반환한다.
	// (arr[mid-1] < key 이면서 arr[mid] >= key 인 최소의 mid)

	// (참고) 벡터의 경우 해당 이터레이터에서 v.begin()을 빼면 몇 번째 인자인지 알 수 있다.

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