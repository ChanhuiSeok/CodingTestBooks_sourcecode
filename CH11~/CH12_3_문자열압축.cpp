#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> result;

int solution(string s) {
	vector<string> temp;
	string pstr;
	int len = s.size(), startIdx = 0;

	// 최솟값 저장
	int minLength = len;

	// 1개부터 len/2개까지 substr 하면서 부분 문자열로 나눠놓는다.
	for (int part = 1; part <= len / 2; part++) {
		// part개로 문자를 나누기
		while (startIdx + part <= len) {
			pstr = s.substr(startIdx, part);
			temp.push_back(pstr);
			startIdx = startIdx + part;
		}
		// 남는 문자 넣기
		pstr = s.substr(startIdx);
		if (pstr != "") temp.push_back(pstr);

		// 문자열 압축하기
		int curIdx = 0, cnt = 1;
		string target = temp[0];
		string t_cmpStr = "";
		string s_cmpStr = "";

		while (curIdx < temp.size() - 1) {
			// 다음 것과 연속해서 같을 경우 cnt값 증가
			if (target == temp[curIdx + 1])
				cnt += 1;
			
			// 다를 경우, 같았을 때까지 결과 배열에 넣고 cnt 초기화
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

		// 마지막 남은 부분 넣어주기
		if (cnt > 1) s_cmpStr += to_string(cnt) + temp[curIdx];
		else s_cmpStr += temp[curIdx];

		minLength = min(minLength, (int)s_cmpStr.size());
		startIdx = 0; temp.clear();
	}
	return minLength;
}