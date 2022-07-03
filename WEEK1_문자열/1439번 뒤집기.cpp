#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	string str;
	cin >> str;

	int zero = 0; // '0'이 나열되는 횟수
	int one = 0; // '1'이 나열되는 횟수

	int str_length = str.length();
	for (int i = 0; i < str_length; i++) {
		if (i == 0) {
			if (str[i] == '0') zero++;
			else one++;
		}
		if (i > 0) {
			if (str[i] == str[i - 1]) continue;
			else {
				if (str[i] == '0') zero++;
				else one++;
			}
		}
	}

	cout << min(zero, one);
}
