#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

/* 구현(1) - 럭키 스트레이트 */

int main() {
	
	string input;
	cin >> input;

	int length = input.size();
	int left = 0, right = 0;

	for (int i = 0; i < length / 2; i++) 
		left += input[i] - '0';
	
	for (int i = length/2; i < length; i++) 
		right += input[i] - '0';
	
	if (left == right) {
		cout << "LUCKY";
	}
	else
		cout << "READY";

	return 0;
}