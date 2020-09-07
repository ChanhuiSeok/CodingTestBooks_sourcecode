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
	if (a.first > b.first) { // �������� ��������
		return true;
	}
	else if (a.first == b.first) {
		if (a.second < b.second) { // �������� ��ȣ�� ��������
			return true;
		}
	}
	return false;
}

vector<int> solution(int N, vector<int> stages) {
	// Ȯ��, �������� ��ȣ
	vector<pair<double, int>> v_info;
	vector<int> answer;

	// �� ���������� ���� �ִ� ����� ���� info�� �ִ´�.
	for (int i = 0; i < stages.size(); i++) {
		info[stages[i]] += 1;
	}

	// 1������������ ���ʴ�� ���鼭 Ȯ���Ѵ�.
	int num = stages.size(); // ��ü ���� �̿����� ��
	for (int i = 1; i <= N; i++) {
		double prob;
		if (num != 0) prob = (double)info[i] / (double)num;	
		else if (num == 0) prob = 0; // 0 ������ ����
		
		v_info.push_back({ prob, i });
		num -= info[i];
	}

	sort(v_info.begin(), v_info.end(), comp);

	for (int k = 0; k < v_info.size(); k++) {
		answer.push_back(v_info[k].second);
	}

	return answer;
}
