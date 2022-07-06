#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string number[10] = {
	"zero", "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine"
};

int M, N;
int result_num[100]; // index 정렬
string num_str[100]; // string 정렬

string findNumStr(string str, int strLen) {
	string result = "";
	int tmp_cnt = 0; // 한자리, 두자리 숫자 여부 판단

	for (int i = 0; i < 2; i++) {
		if (tmp_cnt == 0) {
			result += number[int(str[i] - 48)];

			if (strLen == 2) { // 두자리 숫자
				result += " ";
				tmp_cnt++;
			}
			else { // 한자리 숫자
				return result;
			}
		}
		// 두자리 숫자
		else {
			result += number[int(str[i] - 48)];
		}
	}

	return result;
}

bool compare(int a, int b) {
	// 정렬 기준 : string
	// 실제로 정렬되는 것 : 숫자
	return num_str[a] < num_str[b];
}

int main() {
	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		string tmp_i = to_string(i);
		result_num[i] = i;
		num_str[i] = findNumStr(tmp_i, tmp_i.length());
	}

	// string 정렬 기준으로 숫자를 정렬함
	sort(result_num + M, result_num + N + 1, compare);

	int tmp_count = 0;
	for (int i = M; i <= N; i++) {
		if (tmp_count == 10) {
			cout << endl;
			tmp_count = 0;
		}
		cout << result_num[i] << " ";
		tmp_count++;
	}
}
