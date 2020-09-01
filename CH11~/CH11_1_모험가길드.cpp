#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

/* �׸��� 01 : ���谡 ���*/
vector<int> input;

int main() {

	int N, data;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &data);
		input.push_back(data);
	}

	sort(input.begin(), input.end());

	// �������� X�� ���谡�� �ݵ�� X�� �̻����� ������ �׷쿡 �����ؾ� ��
	// �������� 1�� ���谡 - �ݵ�� 1�� �̻� ������ �׷쿡 �����ؾ� ��
	// �� ������ �׷���� ������ �����Ƿ� ������ 1�� ���谡�� 1���� �׷����� �����
	// �׷���� �� ������ ���̴�.

	int all_grp = 0, cnt = 0;

	for (int k = 0; k < input.size(); k++) {
		cnt += 1; // �׷�� 1 ����
		if (cnt >= input[k]) { // ���� �׸����� ������ �̻��̸�
			all_grp += 1; // ��ü �׷�� 1 ����
			cnt = 0; // ���� �׷��� ���� cnt �ʱ�ȭ
		}
	}

	printf("%d", all_grp);

	return 0;
}