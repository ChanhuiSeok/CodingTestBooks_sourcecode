#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	/* ������ ���� ������ �л� ��� */
	int N;
	cin >> N;

	map<int, string> maps;
	vector<pair<int, string>> vecs;

	string name;
	int score;

	// c++ map �ڷᱸ���� insert �� key ���� �ڵ� �������� ���ĵǾ� �־�����.
	for (int i = 0; i < N; i++) {
		cin >> name >> score;
		maps.insert({ score,name });
	}

	// ���
	map<int, string>::iterator iter;
	for (iter = maps.begin(); iter != maps.end(); iter++) {
		cout << iter->second << ' ';
	}

	return 0;

}