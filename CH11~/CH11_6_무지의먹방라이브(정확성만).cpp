#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

/* 그리디 06 - 무지의 먹방 라이브 (정확도만 100%인 코드) */

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int n = food_times.size();
	int idx = 0, i = 0;
	int cnt_n0 = 0;

	while(1){
		idx = i % n;

		if (k == 0) {
			// 0이 아닌 것을 찾을 때까지 반복
			while (1) {
				if (food_times[idx] == 0) {
					i++;
					idx = i % n;
				}
				else if (food_times[idx] != 0) {
					break;
				}
			}
			break;
		}

		// 음식이 남아 있다면? 1 감소시킨다. 시간을 흐르게 하고, 다음 인덱스로 이동시킨다.
		if (food_times[idx] != 0) {
			food_times[idx] -= 1;
			k -= 1;
			// 다음 인덱스로 향하게 함
			i += 1;
		}
		// 0일 경우
		else if (food_times[idx] == 0) {
			i += 1;
		}

		bool flag = true;
		for (int i = 0; i < food_times.size(); i++) {
			if (food_times[i] != 0){
				flag = false;
				break;
			}
		}
		if (flag) return -1;
	}

	answer = idx + 1;
	return answer;
}

int main() {

	vector<int> food_times = {3,1,1,1,2,4,3};
	long long k = 12;

	int result = solution(food_times, k);
	cout << result;

	return 0;
}