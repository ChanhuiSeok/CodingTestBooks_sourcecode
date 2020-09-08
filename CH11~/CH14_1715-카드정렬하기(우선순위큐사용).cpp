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
		// ���� ť�� �ְ�...
		pq.push(input);
	}

	// �켱���� ť�� �ִ� ����!
	// ī��� ������ ���� ���� ������ ���ϴ°� ���� ������� �ּҸ� ���� �� ����
	// ���� ���� �ٽ� ť�� �ְ� ���� ���� �� ���� ���� ���� �ݺ��ϸ� ��!
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