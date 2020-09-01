#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

/* ±×¸®µð 05 */
int weight[11];

int main() {

	int N, M, input;
	cin >> N >> M;

	int result = 0;

	for (int i = 0; i < N; i++) {
		cin >> input;
		weight[input] += 1;
	}
	
	for (int i = 1; i <= M; i++) {
		N = N - weight[i];
		result = result + (weight[i] * N);
	}
	
	cout << result;
	
	return 0;
}