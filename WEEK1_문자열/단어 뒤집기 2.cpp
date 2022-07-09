#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

stack<char> s;

int main() {
	string str;
	getline(cin, str);

	bool tag = false; // tag 내부 문자 여부 check
	int str_length = str.length();

	for (int i = 0; i < str_length; i++) {
		// 현재 문자가 '<'라면, tag 상태 true
		if (str[i] == '<') {
			// 태그 사이에 하나의 단어가 있는 경우, 단어 출력을 해야함
			// 마지막 태그 시작 전에 stack 출력
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}

			cout << str[i];
			tag = true;
		}

		// 현재 문자가 '>'라면, tag 상태 false
		else if (str[i] == '>') {
			cout << str[i];
			tag = false;
		}

		// tag 상태가 true -> tag 내부 문자열은 그대로 출력
		else if (tag) {
			cout << str[i];
		}

		// 현재 문자가 공백인 경우 -> 공백 앞의 문자열을 뒤집어서 출력
		else if (str[i] == ' ') {
			// 뒤집어놓은 문자열을 출력함
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << str[i]; // 공백 출력
		}

		// 일반 문자열 -> 뒤집을 준비를 위해 stack에 저장
		else {
			s.push(str[i]);
		}

	}

	// 모든 태그가 끝나고, 남은 단어 출력을 위해 stack 털어주기
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}
