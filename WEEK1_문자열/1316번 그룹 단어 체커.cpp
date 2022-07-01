#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool checkGroup(string str) {
	bool alpha[27] = { false, };

	int str_length = str.length();
	for (int i = 0; i < str_length; i++) {
		if (alpha[(int(str[i]) - 97)]) { // 이미 true로 지정된 요소에 접근하면
			// 이전 문자와 같은 문자가 아닌 경우여야함
			if((int(str[i - 1]) - 97) != (int(str[i]) - 97)) return false; // 그룹 단어가 아님
		}

		alpha[int(str[i]) - 97] = true; // 각 문자를 검사하여 true로 바꿔줌
	}

	return true; // 그룹 단어임
}

int main() {
	int testcase;
	cin >> testcase;

	int count = 0;

	while (testcase--) {
		string str;
		cin >> str;

		if (checkGroup(str)) count++;

	}

	cout << count;
}
