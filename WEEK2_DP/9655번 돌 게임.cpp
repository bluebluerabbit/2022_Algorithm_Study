#include <iostream>
#include <vector>
using namespace std;

int dp[1000];

int main() {
	int N;
	cin >> N;

	dp[1] = 1; // 1
	dp[2] = 2; // 1->1
	dp[3] = 1; // 3
	// dp[4] = 2 // 3->1
	// dp[5] = 3 // 3->1->1
	
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 3] + 1;
	}

	// 돌을 가져가는 횟수가 짝수
	if (dp[N] % 2 == 0) {
		cout << "CY";
	}
	// 돌을 가져가는 횟수가 홀수
	else {
		cout << "SK";
	}
}
