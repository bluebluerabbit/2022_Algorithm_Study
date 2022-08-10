#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum = 0;
int cnt = 0;

int checkFirst(string N) {
	int firstSum = 0;
	for (int i = 0; i < N.length(); i++) {
		firstSum += ((int)N[i] - '0');
	}

	return firstSum;
}

long long check(long long N) {
	int digit;

	if (N > 0) {
		digit = N % 10;
		sum += digit;
		check(N / 10);
		// cout << "digit : " << digit << "\n";
	}

	// cout << "sum : " << sum << "\n";
	return sum;
}

int main() {
	string strN;
	cin >> strN;

	int intN = checkFirst(strN);

	if (strN.length() == 1) {
		if (intN == 3 || intN == 6 || intN == 9) {
			cout << cnt << "\n";
			cout << "YES";
			return 0;
		}
		else {
			cout << cnt << "\n";
			cout << "NO";
			return 0;
		}
	}
	else {
		cnt++;
		if ((intN / 10) < 1) {
			if (intN == 3 || intN == 6 || intN == 9) {
				cout << cnt << "\n";
				cout << "YES";
				return 0;
			}
			else {
				cout << cnt << "\n";
				cout << "NO";
				return 0;
			}
		}
	}


	while (1) {
		long long tmp = check(intN);
		cnt++;
		// cout << "tmp : " << tmp << "\n";
		if ((tmp / 10) >= 1) {
			sum = 0;
			intN = tmp;
		}
		else {
			if (tmp == 3 || tmp == 6 || tmp == 9) {
				cout << cnt << "\n";
				cout << "YES";
				return 0;
			}
			else {
				cout << cnt << "\n";
				cout << "NO";
				return 0;
			}
		}
	}
}
