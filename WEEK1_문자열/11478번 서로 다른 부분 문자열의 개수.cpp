#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;

	vector<string> v; // 쪼갠 문자열 저장

	int str_length = str.length();
	for (int i = 0; i < str_length; i++) { // 0
		string tmp = "";
		for (int j = i; j < str_length; j++) { // 0~4
			tmp += str[j];
			v.push_back(tmp);
		}
	}

	// 중복 문자열 제거
	sort(v.begin(), v.end()); // 원소 정렬
	v.erase(unique(v.begin(), v.end()), v.end()); // 중복 원소 뒤로 보내고 뒷부분 삭제

	cout << v.size() << endl;
}
