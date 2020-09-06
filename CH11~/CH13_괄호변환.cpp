#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

// �׻� ������ ���ڴ� �������� ��ȣ ���ڿ��̹Ƿ�,
// �ùٸ� ��ȣ ���ڿ����� �Ǵ��ϴ� �Լ��� �ʿ���
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

// w�� u, v �� ���ڿ��� �и��ϴ� �Լ�
// �� u�� �� �̻� �и� �Ұ����� �������� ��ȣ ���ڿ��θ�
// v�� ���� �κ��̰� �� ���ڿ��� ����
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

	ps = partial(w); // ���ڿ� �и�

	// ������ ��� ���ڿ��� u�� �̾� ���� ���� ��ȯ�� ���ε�
	if (isCorrect(ps.first)) { 
		// 3-1. u�� �ùٸ� ��ȣ ���ڿ��̸� v�� ���� 1�ܰ���� �ٽ� ���� �� �̾� ����
		return ps.first + making(ps.second);
	}
	// ���ڿ� u�� �ùٸ� ��ȣ ���ڿ��� �ƴ� ���
	else {
		string temp = "";
		temp += "(";
		temp += making(ps.second);
		temp += ")";
		
		// substr �� ���� �ٸ� ������ ������ �����ؾ� �� ���� �ݿ��ȴ�!!
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