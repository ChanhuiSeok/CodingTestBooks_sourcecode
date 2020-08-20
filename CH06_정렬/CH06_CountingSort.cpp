#define _CRT_SECURE_NO_WARNINGS
#define INF 999999
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ��� ������ ���� 0���� ũ�ų� ���ٰ� ����
vector<int> arr = { 7,5,9,1,3,1,6,2,9,1,4,8,1,5,2 };

int main() {

	/* Count sort */
	// ��������� �� ����� ���� �˰���(����,����,�� ��)�� �ƴϴ�.
	// ���� ū �����Ϳ� ���� ���� �������� ������ ��� ��� �� �ִ� �ϳ��� ����Ʈ��
	// ������ �߰� �����ϰ�, �ű⿡ ���� Ƚ���� ī��Ʈ�Ѵ�.
	// �־��� ��쵵 O(N+K) (K�� �ִ�) �� �����Ѵ�.
	// �� ������ ũ�� ������ �������̰� ���� ���·� ǥ�� �����ϸ� �ּҿ� �ִ� ���̰�
	// 1�鸸�� ���� ���� �� ȿ�������� ��� �����ϴ�.

	// ���� ū �����Ϳ� ���� ���� �������� ������ ��� ��� �� �ִ� �ϳ��� ����Ʈ ����
	// ���� ū �� ã��
	int max = -10000000;
	for (int i = 0; i < arr.size(); i++) {
		if (max < arr[i])
			max = arr[i];
	}
	// ����Ʈ ����
	vector<int> tempArr(max + 1); // max + 1 ����ŭ 0���� �ʱ�ȭ
	
	// �� �����Ϳ� �ش��ϴ� �ε����� �� ����
	for (int i = 0; i < arr.size(); i++) {
		tempArr[arr[i]] += 1;
	}
	// ��ϵ� ������� ī���õ� Ƚ����ŭ �ε��� ���
	for (int i = 0; i < tempArr.size(); i++) {
		for (int j = 0; j < tempArr[i]; j++) {
			cout << i << " ";
		}
	}

	return 0;

}