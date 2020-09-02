#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

/* 구현(1) - 럭키 스트레이트 */

vector<char> strings;

int main() {
	
	string s;
	cin >> s;

	int nums = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			strings.push_back(s[i]);
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			nums += s[i] - '0';
		}
	}
	sort(strings.begin(), strings.end());

	for (int i = 0; i < strings.size(); i++) 
		cout << strings[i];
	cout << nums;

	return 0;
}