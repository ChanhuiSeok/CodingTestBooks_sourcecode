#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

// 항상 들어오는 문자는 균형잡힌 괄호 문자열이므로,
// 올바른 괄호 문자열인지 판단하는 함수가 필요함
bool isCorrect(string s) {
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push(s[i]);
		else if (!st.empty() && st.top() == '(' && s[i] == ')') {
			st.pop();
		}
	}

	if (st.empty())
		return true;
	else
		return false;
}

// w를 u, v 두 문자열로 분리하는 함수
// 단 u는 더 이상 분리 불가능한 균형잡힌 괄호 문자열로만
// v는 남은 부분이고 빈 문자열도 가능
pair<string, string> partial(string w) {
	stack<char> st;

	int cnt[2] = { 0, 0 };
	int pIdx = 0;

	for (int i = 0; i < w.size(); i++) {
		if ((cnt[0] != 0 && cnt[1] != 0) &&
			cnt[0] == cnt[1]) break;

		if (w[i] == '(') {
			cnt[0]++; pIdx++;
		}
		else if (w[i] == ')') {
			cnt[1]++; pIdx++;
		}
	}

	string u = w.substr(0, pIdx);
	string v = w.substr(pIdx);

	return { u,v };
}


string making(string w) {

	pair<string, string> ps;

	if (w == "") return "";

	ps = partial(w); // 문자열 분리

	// 수행한 결과 문자열을 u에 이어 붙인 다음 반환할 것인데
	if (isCorrect(ps.first)) { 
		// 3-1. u가 올바른 괄호 문자열이면 v에 대해 1단계부터 다시 수행 후 이어 붙임
		return ps.first + making(ps.second);
	}
	// 문자열 u가 올바른 괄호 문자열이 아닐 경우
	else {
		string temp = "";
		temp += "(";
		temp += making(ps.second);
		temp += ")";
		
		// substr 한 값은 다른 변수에 별도로 저장해야 그 값이 반영된다!!
		string changed = ps.first.substr(1, ps.first.size() - 2);

		for (int i = 0; i < changed.size(); i++) {
			if (changed[i] == '(')
				changed[i] = ')';
			else if (changed[i] == ')')
				changed[i] = '(';
		}
		temp += changed;
		return temp;
	}
}

string solution(string p) {

	if (isCorrect(p)) return p;

	string result = making(p);
	return result;
	
}


int main() {

	string t = ")(";

	solution(t);

}