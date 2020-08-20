#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	/* 성적이 낮은 순서로 학생 출력 */
	int N;
	cin >> N;

	map<int, string> maps;
	vector<pair<int, string>> vecs;

	string name;
	int score;

	// c++ map 자료구조는 insert 시 key 기준 자동 오름차순 정렬되어 넣어진다.
	for (int i = 0; i < N; i++) {
		cin >> name >> score;
		maps.insert({ score,name });
	}

	// 출력
	map<int, string>::iterator iter;
	for (iter = maps.begin(); iter != maps.end(); iter++) {
		cout << iter->second << ' ';
	}

	return 0;

}