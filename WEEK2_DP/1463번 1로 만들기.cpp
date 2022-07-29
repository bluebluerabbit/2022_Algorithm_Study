#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000000

int dp[MAX];

int main() {
	int N;
	cin >> N;
	
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}

	cout << dp[N];
}
