#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 현재 문자가 모음인지 자음인지 check
char checkVC(char c) {
	// 모음
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return 'V';
	}
	// 자음
	else {
		return 'C';
	}
}

// 좋은 비밀번호일까요?
string checkGoodPw(string str) {
	bool check_vowels = false; // 모음 존재 여부
	bool check_consonants = false; // 자음 존재 여부

	int check_vowels_3 = 0; // 모음 3개 연속 check
	int check_consonants_3 = 0; // 자음 3개 연속 check
	bool two = false; // 같은 글자 2번 연속 check

	int str_length = str.length();

	// 모음(a, e, i, o, u) 하나를 반드시 포함하여야 한다.
	for (int i = 0; i < str_length; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			check_vowels = true;
		}
	}

	if (!check_vowels) return "not acceptable.";


	// 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
	for (int i = 0; i < str_length; i++) {
		// 모음 or 자음 3개 check
		
		// 현재 문자가 모음 -> 3개 연속하는지 check
		if (checkVC(str[i]) == 'V') {
			check_vowels_3++;
			if (checkVC(str[i + 1]) == 'V' && (i+1) < str_length) {
				check_vowels_3++;
				if (checkVC(str[i + 2]) == 'V' && (i + 2) < str_length) {
					check_vowels_3++;
				}
				else {
					check_vowels_3 = 0;
				}
			}
			else {
				check_vowels_3 = 0;
			}
		}

		// 현재 문자가 자음 -> 3개 연속하는지 check
		if (checkVC(str[i]) == 'C') {
			check_consonants_3++;
			if (checkVC(str[i + 1]) == 'C' && (i + 1) < str_length) {
				check_consonants_3++;
				if (checkVC(str[i + 2]) == 'C' && (i + 2) < str_length) {
					check_consonants_3++;
				}
				else {
					check_consonants_3 = 0;
				}
			}
			else {
				check_consonants_3 = 0;
			}
		}
		
		// 연속하면 안 좋은 비밀번호임
		if (check_vowels_3 >= 3) return "not acceptable.";
		if (check_consonants_3 >= 3) return "not acceptable.";
	}

	// 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
	for (int i = 0; i < str_length; i++) {
		if ((str[i] == str[i + 1]) && (i + 1) < str_length &&
			str[i] != 'e' && str[i] != 'o') two = true;
		if (two) return "not acceptable.";
	}

	return "acceptable.";
}

int main() {
	while (1) {
		string str;
		cin >> str;

		if (str == "end") break;

		cout << "<" << str << ">" << " is " << checkGoodPw(str) << endl;
	}
}
