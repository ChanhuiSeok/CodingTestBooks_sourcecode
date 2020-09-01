#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

/* 그리디 01 : 모험가 길드*/
vector<int> input;

int main() {

	int N, data;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &data);
		input.push_back(data);
	}

	sort(input.begin(), input.end());

	// 공포도가 X인 모험가는 반드시 X명 이상으로 구성한 그룹에 참여해야 함
	// 공포도가 1인 모험가 - 반드시 1명 이상 구성한 그룹에 참여해야 함
	// 이 문제는 그룹수가 많으면 좋으므로 공포도 1인 모험가는 1명인 그룹으로 만들면
	// 그룹수가 더 많아질 것이다.

	int all_grp = 0, cnt = 0;

	for (int k = 0; k < input.size(); k++) {
		cnt += 1; // 그룹원 1 증가
		if (cnt >= input[k]) { // 현재 그릅원이 공포도 이상이면
			all_grp += 1; // 전체 그룹수 1 증가
			cnt = 0; // 다음 그룹을 위해 cnt 초기화
		}
	}

	printf("%d", all_grp);

	return 0;
}