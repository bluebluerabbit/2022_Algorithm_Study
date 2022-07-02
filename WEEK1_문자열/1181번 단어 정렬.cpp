#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str_arr[20000]; // string 저장

bool compare(string a, string b) {
	// i번째 길이 == (i + 1)번째 길이
	if (a.length() == b.length()) {
		// 사전순 정렬
		return a < b;
	}
	// i번째 길이와 (i + 1)번째 길이가 다르다면, 길이가 짧은 것을 우선시
	else {
		return a.length() < b.length();
	}
}

int main() {
	int n;
	cin >> n;

	// 문자열 저장
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		str_arr[i] = str;
	}

	sort(str_arr, str_arr + n, compare);

	// 정렬된 문자열 배열 출력
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cout << str_arr[i] << endl;
		}
		else if (str_arr[i] != str_arr[i - 1]) { // 중복 문자열 제거
			cout << str_arr[i] << endl;
		}
	}
}
