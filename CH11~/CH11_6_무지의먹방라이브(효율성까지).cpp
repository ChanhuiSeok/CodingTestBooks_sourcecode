#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

/* �׸��� 06 - ������ �Թ� ���̺� (��Ȯ���� ȿ���� ��� ����� �ڵ�)*/
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int solution(vector<int> food_times, long long k) {
	ll tmpSum = 0;
	for (int i = 0; i < food_times.size(); i++) {
		tmpSum += food_times[i];
	}
	if (tmpSum <= k) return -1;

	// food_times�� ���� �Դ� �� �ɸ��� �ð����� �������� �����Ѵ�.
	// �̰���, pair�� <�ð�, ���Ĺ�ȣ> �� �����Ͽ� �켱���� ť�� �־���´�.
	for (int i = 0; i < food_times.size(); i++) {
		pq.push({ food_times[i], i + 1 });
	}

	// ���� �Դµ� ���� �ɸ��� ���ĺ��� ������ �Ѳ����� �ð��� ���ҽ�Ų��.
	ll sum = 0;
	ll prev = 0;
	ll n = pq.size();
	while (1) {
		ll tmpSum = 0;
		// (���� ���� �ð� - ���� ���� �ð�) * (0�� �ƴ� food�� ����)
		// �� �� ���� �� ����.
		sum = ((pq.top().first) - prev) * pq.size();
		if (sum > k) {
			break;
		}
		else if (sum <= k) {
			k -= sum;
			prev = pq.top().first;
			pq.pop();
		}
	}

	// ���� �ð��� ���� ������� �Ծ�鼭 �ߴܵǾ��� ���� ���� ��ȣ�� ���Ѵ�.
	int idx = k % pq.size();
	vector<pair<int, int>> result;
	while (!pq.empty()) {
		int num = pq.top().second;
		ll time = pq.top().first;
		pq.pop();
		result.push_back({ num,time });
	}
	sort(result.begin(), result.end());
	return result[idx].first;
}

int main() {
	
	vector<int> food_times = {8,6,4};
	long long k = 15;

	int result = solution(food_times, k);
	cout << result;

	return 0;
}