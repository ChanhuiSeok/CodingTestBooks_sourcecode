#define _CRT_SECURE_NO_WARNINGS
#define INF 999999
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 모든 원소의 값이 0보다 크거나 같다고 가정
vector<int> arr = { 7,5,9,1,3,1,6,2,9,1,4,8,1,5,2 };

int main() {

	/* Count sort */
	// 계수정렬은 비교 기반의 정렬 알고리즘(선택,삽입,퀵 등)이 아니다.
	// 가장 큰 데이터와 가장 작은 데이터의 범위가 모두 담길 수 있는 하나의 리스트를
	// 별도로 추가 생성하고, 거기에 나온 횟수를 카운트한다.
	// 최악의 경우도 O(N+K) (K는 최댓값) 을 보장한다.
	// 단 데이터 크기 범위가 제한적이고 정수 형태로 표현 가능하며 최소와 최대 차이가
	// 1백만을 넘지 않을 때 효과적으로 사용 가능하다.

	// 가장 큰 데이터와 가장 작은 데이터의 범위가 모두 담길 수 있는 하나의 리스트 생성
	// 가장 큰 값 찾기
	int max = -10000000;
	for (int i = 0; i < arr.size(); i++) {
		if (max < arr[i])
			max = arr[i];
	}
	// 리스트 생성
	vector<int> tempArr(max + 1); // max + 1 개만큼 0으로 초기화
	
	// 각 데이터에 해당하는 인덱스의 값 증가
	for (int i = 0; i < arr.size(); i++) {
		tempArr[arr[i]] += 1;
	}
	// 기록된 정보대로 카운팅된 횟수만큼 인덱스 출력
	for (int i = 0; i < tempArr.size(); i++) {
		for (int j = 0; j < tempArr[i]; j++) {
			cout << i << " ";
		}
	}

	return 0;

}