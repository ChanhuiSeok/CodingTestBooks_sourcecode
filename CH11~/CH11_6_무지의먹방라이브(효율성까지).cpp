#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

/* 그리디 06 - 무지의 먹방 라이브 (정확도와 효율성 모두 고려한 코드)*/
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int solution(vector<int> food_times, long long k) {
	ll tmpSum = 0;
	for (int i = 0; i < food_times.size(); i++) {
		tmpSum += food_times[i];
	}
	if (tmpSum <= k) return -1;

	// food_times의 값을 먹는 데 걸리는 시간으로 오름차순 정렬한다.
	// 이것은, pair로 <시간, 음식번호> 를 지정하여 우선순위 큐에 넣어놓는다.
	for (int i = 0; i < food_times.size(); i++) {
		pq.push({ food_times[i], i + 1 });
	}

	// 음식 먹는데 적게 걸리는 음식부터 꺼내서 한꺼번에 시간을 감소시킨다.
	ll sum = 0;
	ll prev = 0;
	ll n = pq.size();
	while (1) {
		ll tmpSum = 0;
		// (현재 음식 시간 - 이전 음식 시간) * (0이 아닌 food의 갯수)
		// 을 한 번에 빼 본다.
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

	// 남은 시간을 원래 순서대로 먹어가면서 중단되었을 때의 음식 번호를 구한다.
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