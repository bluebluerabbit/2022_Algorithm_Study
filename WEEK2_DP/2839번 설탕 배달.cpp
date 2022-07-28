#include <iostream>
#include <vector>
using namespace std;

int dp[5000];

int main() {
	int N;
	cin >> N;

	// 3kg, 5kg
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;

	for (int i = 6; i <= N; i++) {
		if (i % 5 == 0) {
			dp[i] = i / 5;
		}
		else if (i % 3 == 0) {
			dp[i] = dp[i - 3] + 1;
		}
		else {
			if (dp[i - 3] != -1) {
				dp[i] = dp[i - 3] + 1;
			}
			else {
				dp[i] = -1;
			}
		}
	}

	cout << dp[N];
}
