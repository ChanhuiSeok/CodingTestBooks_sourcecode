#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <map>

#define None -1e9-1

using namespace std;

// C++�� replace_all �Լ�. str���� pattern�� replace�� �ϰ������� �����Ѵ�.
string replace_all(const std::string& str, const std::string& pattern, const std::string& replace) {
	string result = str;
	string::size_type pos = 0;
	string::size_type offset = 0;
	while ((pos = result.find(pattern, offset)) != std::string::npos)
	{
		result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);
		offset = pos + replace.size();
	}
	return result;
}

// lower, upper_bound�� Ȱ���Ͽ� ������ ���� �Լ�
int cnt_value(vector<string>& v, string leftVal, string rightVal) {

	vector<string>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightVal);
	vector<string>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftVal);
	return rightIndex - leftIndex;

}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	vector<vector<string>> origin_words;
	vector<vector<string>> reversed_words;

	origin_words.resize(10001);
	reversed_words.resize(10001);

	for (int i = 0; i < words.size(); i++) {
		int size = words[i].size();
		origin_words[size].push_back(words[i]);

		reverse(words[i].begin(), words[i].end());
		reversed_words[size].push_back(words[i]);
	}

	// lower, upper_bound�� ����Ϸ��� �������� ������ �Ǿ� �־�� �մϴ�.
	for (int i = 0; i < 10001; i++) {
		if (origin_words[i].size() == 0) continue;
		sort(origin_words[i].begin(), origin_words[i].end());
		sort(reversed_words[i].begin(), reversed_words[i].end());
	}

	for (int k = 0; k < queries.size(); k++) {

		int cnt = 0;
		string target = queries[k];
		int targetSize = target.size();

		if (target[0] != '?') {
			cnt = cnt_value(origin_words[targetSize], replace_all(target, "?", "a"), replace_all(target, "?", "z"));
			answer.push_back(cnt);
		}
		else {
			reverse(target.begin(), target.end()); // ã���� �ϴ� �� ������, �ؿ����� ������ words �迭���� ã��
			cnt = cnt_value(reversed_words[targetSize], replace_all(target, "?", "a"), replace_all(target, "?", "z"));
			answer.push_back(cnt);
		}
	}

	return answer;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };

	vector<int> result = solution(words, queries);

	return 0;
}