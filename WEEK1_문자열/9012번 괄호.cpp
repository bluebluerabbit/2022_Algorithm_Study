#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

string VPS(string str) {
	stack<char> s;

	int str_length = str.length();
	for (int i = 0; i < str_length; i++) {
		// '(' 넣기
		if (str[i] == '(') {
			s.push(str[i]);
		}
		// stack에 '('가 존재하고 현재 문자가 ')'이면 pop
		else if (str[i] == ')' && s.empty() == false) {
			s.pop();
		}
		// stack이 비어있고 현재 문자가 ')'이면 NO
		else if (str[i] == ')' && s.empty() == true) {
			return "NO";
		}
	}

	if (s.empty()) return "YES";
	else return "NO";
}


int main() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		string str;
		cin >> str;

		cout << VPS(str) << endl;
	}
}
