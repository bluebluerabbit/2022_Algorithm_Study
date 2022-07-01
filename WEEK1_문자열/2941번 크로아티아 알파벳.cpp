#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	// 크로아티아 알파벳 배열, 이 외의 알파벳은 한 글자씩 센다.
	string cro[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	// 지금 검사하고 있는 문자열이 크로아티아 알파벳이었나요?
	bool is_this_cro = false;

	int count = 0;

	string str;
	cin >> str;

	int str_length = str.length();
	for (int i = 0; i < str_length; i++) {
		string tmp_str = ""; // 크로아티아 알파벳 체크
		string d_tmp_str = ""; // 크로아티아 알파벳 체크 (d로 시작하는 경우, 2글자와 3글자 크로아티아 알파벳 존재)
		is_this_cro = false;

		// c, l, d, n, s, z로 시작하는 경우 -> 크로아티아 알파벳 경우
		if (str[i] == 'c' || str[i] == 'l' || str[i] == 'd' ||
			str[i] == 'n' || str[i] == 's' || str[i] == 'z') {
			if (i != (str_length - 1)) {
				// 검사할 2글자 string
				tmp_str.push_back(str[i]);
				tmp_str.push_back(str[i + 1]);

				// 'dz=' 검사용 (3글자 string)
				if (str[i] == 'd' && i != (str_length - 2)) {
					d_tmp_str += tmp_str;
					d_tmp_str.push_back(str[i + 2]);
				}

				// 크로아티아 알파벳 검사
				for (int j = 0; j < 8; j++) {
					if (tmp_str == cro[j]) { // 2글자 string이 크로아티아 알파벳인 경우
						i += 1; // 현재보다 다다음 문자를 검사

						is_this_cro = true; // 지금 검사한 건 크로아티아 알파벳이야!
						count++;
					}
					else if (d_tmp_str == cro[j]) { // 3글자 string이 크로아티아 알파벳인 경우
						i += 2; // 현재보다 다다다음 문자를 검사

						is_this_cro = true;
						count++;
					}
				}
			}

			// 크로아티아 알파벳 시작 문자였지만, 크로아티아 알파벳이 아닌 경우
			if (is_this_cro == false) {
				if (str[i] != '-' && str[i] != '=') {
					count++;
				}
			}
		}

		// 크로아티아 알파벳 시작 문자가 아닌 경우
		else {
			if (str[i] != '-' && str[i] != '=') {
				count++;
			}
		}
	}

	cout << count << endl;
}
