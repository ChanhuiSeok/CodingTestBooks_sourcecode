#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

/* �׸��� 06 - ������ �Թ� ���̺� (��Ȯ���� 100%�� �ڵ�) */

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int n = food_times.size();
	int idx = 0, i = 0;
	int cnt_n0 = 0;

	while(1){
		idx = i % n;

		if (k == 0) {
			// 0�� �ƴ� ���� ã�� ������ �ݺ�
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

		// ������ ���� �ִٸ�? 1 ���ҽ�Ų��. �ð��� �帣�� �ϰ�, ���� �ε����� �̵���Ų��.
		if (food_times[idx] != 0) {
			food_times[idx] -= 1;
			k -= 1;
			// ���� �ε����� ���ϰ� ��
			i += 1;
		}
		// 0�� ���
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