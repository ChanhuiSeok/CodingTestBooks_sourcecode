#define pb push_back
#define pillar 0
#define beam 1
#define setup 1
#define INF 1000000

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[110][110][2]; // ������

bool check(int n, int y, int x) {

	bool flag = true;
	// ��� Ȯ��
	if (arr[y][x][pillar] == setup) {

		// �� �Ʒ��� ����� �ְų�, �� �ʿ� ���� ���� ��� ��� ��ȿ��
		if (y == 0 || arr[y - 1][x][pillar] == 1 || arr[y][x][beam] == 1 ||
			(x > 0 && arr[y][x - 1][beam] == 1)) {
			flag = true;
		}

		else
			return false;
	}

	// �� Ȯ��
	if (arr[y][x][beam] == setup) {

		// �� ��ġ �� ���� �� �ϳ� �ؿ� ����� ������ ��ȿ��
		// Ȥ�� �� ���� ���� �־ ��ȿ��
		if ((y > 0 && arr[y - 1][x][pillar] == 1) || (y > 0 && arr[y - 1][x + 1][pillar] == 1)
			|| (x > 0 && x < n && arr[y][x - 1][beam] == 1 && arr[y][x + 1][beam] == 1)) {
			flag = true;
		}
		else
			return false;
	}
	return true;

}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	vector<int> temp;

	// ó���� �������� ��� -�� �ʱ�ȭ
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			arr[i][j][0] = -INF;
			arr[i][j][1] = -INF;
		}
	}

	for (int i = 0; i < build_frame.size(); i++) {
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int category = build_frame[i][2];
		int crtORdel = build_frame[i][3];

		// ��ġ
		if (crtORdel == 1) {
			// ����� ���
			if (category == pillar) {
				arr[y][x][pillar] = setup; // �ϴ� ��ġ �� ����
				if (check(n, y, x) == false) {
					arr[y][x][pillar] = -INF;
				}
			}

			// ���� ���
			else {
				arr[y][x][beam] = setup; // �ϴ� ��ġ �� ����
				if (check(n, y, x) == false) {
					arr[y][x][beam] = -INF;
				}
			}
		}

		// ����
		else {
			// ����� ���
			if (category == pillar) {
				if (arr[y][x][pillar] == setup) {
					arr[y][x][pillar] = -INF; // �ϴ� ���� �� ����
					// ����� ������ ��� 0. �� �ڸ� �˻�
					// 1. �� ���� �ִ� ����� ��ȿ�� ����
					// 2. �� ������� ������ �� �־��� ���� ��ġ �˻�
					if (!(check(n, y, x) && check(n, y + 1, x) && check(n, y + 1, x - 1))) {
						arr[y][x][pillar] = setup;
					}
				}
			}

			// ���� ���
			else {
				if (arr[y][x][beam] == setup) {
					arr[y][x][beam] = -INF; // �ϴ� ���� �� ����
					// ���� ������ ���
					// 1. �� ��ǥ �Ӹ� �ƴ϶� �� ���� �ִ� ���鵵 ��ȿ�� �˻�
					if (!(check(n, y, x) && check(n, y, x - 1) && check(n, y, x + 1))) {
						arr[y][x][beam] = setup;
					}
				}
			}
		}
	}

	vector<int> answer_temp;

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (arr[i][j][pillar] == setup) {
				answer_temp.pb(j);
				answer_temp.pb(i);
				answer_temp.pb(pillar);

				answer.pb(answer_temp);
				answer_temp.clear();
			}
			if (arr[i][j][beam] == setup) {
				answer_temp.pb(j);
				answer_temp.pb(i);
				answer_temp.pb(beam);

				answer.pb(answer_temp);
				answer_temp.clear();
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}