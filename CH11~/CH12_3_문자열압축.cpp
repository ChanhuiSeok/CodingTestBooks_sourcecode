#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> result;

int solution(string s) {
	vector<string> temp;
	string pstr;
	int len = s.size(), startIdx = 0;

	// �ּڰ� ����
	int minLength = len;

	// 1������ len/2������ substr �ϸ鼭 �κ� ���ڿ��� �������´�.
	for (int part = 1; part <= len / 2; part++) {
		// part���� ���ڸ� ������
		while (startIdx + part <= len) {
			pstr = s.substr(startIdx, part);
			temp.push_back(pstr);
			startIdx = startIdx + part;
		}
		// ���� ���� �ֱ�
		pstr = s.substr(startIdx);
		if (pstr != "") temp.push_back(pstr);

		// ���ڿ� �����ϱ�
		int curIdx = 0, cnt = 1;
		string target = temp[0];
		string t_cmpStr = "";
		string s_cmpStr = "";

		while (curIdx < temp.size() - 1) {
			// ���� �Ͱ� �����ؼ� ���� ��� cnt�� ����
			if (target == temp[curIdx + 1])
				cnt += 1;
			
			// �ٸ� ���, ������ ������ ��� �迭�� �ְ� cnt �ʱ�ȭ
			else {
				if (cnt > 1)
					t_cmpStr += to_string(cnt) + target;
				else
					t_cmpStr += target;

				s_cmpStr += t_cmpStr;
				t_cmpStr = ""; target = ""; cnt = 1;
			}
			curIdx++;
			target = temp[curIdx];
		}

		// ������ ���� �κ� �־��ֱ�
		if (cnt > 1) s_cmpStr += to_string(cnt) + temp[curIdx];
		else s_cmpStr += temp[curIdx];

		minLength = min(minLength, (int)s_cmpStr.size());
		startIdx = 0; temp.clear();
	}
	return minLength;
}