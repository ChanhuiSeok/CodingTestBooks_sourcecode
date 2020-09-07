#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int info[200001];

bool comp(const pair<double, int>& a, const pair<double, int>& b) {
	if (a.first > b.first) { // 실패율은 내림차순
		return true;
	}
	else if (a.first == b.first) {
		if (a.second < b.second) { // 스테이지 번호는 오름차순
			return true;
		}
	}
	return false;
}

vector<int> solution(int N, vector<int> stages) {
	// 확률, 스테이지 번호
	vector<pair<double, int>> v_info;
	vector<int> answer;

	// 각 스테이지에 멈춰 있는 사람의 수를 info에 넣는다.
	for (int i = 0; i < stages.size(); i++) {
		info[stages[i]] += 1;
	}

	// 1스테이지부터 차례대로 보면서 확인한다.
	int num = stages.size(); // 전체 게임 이용자의 수
	for (int i = 1; i <= N; i++) {
		double prob;
		if (num != 0) prob = (double)info[i] / (double)num;	
		else if (num == 0) prob = 0; // 0 나누기 방지
		
		v_info.push_back({ prob, i });
		num -= info[i];
	}

	sort(v_info.begin(), v_info.end(), comp);

	for (int k = 0; k < v_info.size(); k++) {
		answer.push_back(v_info[k].second);
	}

	return answer;
}
