#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> res;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		// 먼저 큐에 넣고...
		pq.push(input);
	}

	// 우선순위 큐에 넣는 생각!
	// 카드는 무조건 작은 값의 묶음을 더하는게 최종 결과에서 최소를 얻을 수 있음
	// 더한 값을 다시 큐에 넣고 가장 작은 두 값을 빼는 것을 반복하면 됨!
	int AllSum = 0;
	while (pq.size() != 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		int sum = a + b;
		AllSum += sum;

		pq.push(sum);
	}

	cout << AllSum;

	return 0;
}