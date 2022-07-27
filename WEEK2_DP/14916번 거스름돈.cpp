#include <iostream>
#include <vector>
using namespace std;

int dp[100000];

int main() {
	int n;
	cin >> n;

	// 거스름돈 : 2원, 5원
	// 동전의 개수가 최소가 되도록
	dp[1] = -1;
	dp[2] = 1;

	// 2원을 추가하거나 안 하는 경우로 나누기 위해
	// dp[i-2]가 존재하는 dp[3]부터 탐색 -> dp[1], dp[2]를 기저 상태로 미리 선언해둠
	for (int i = 3; i <= n; i++) {
		// 5로 나누어 떨어짐 (무조건 최소 개수로 나오는 경우)
		if (i % 5 == 0) {
			dp[i] = i / 5;
		}
		else {
			// dp[3]에 대해서 최소 dp[1]이 1 이상이어야만 2원을 추가해서 dp[3]의 최소를 구할 수 있음
			// dp[1]은 0이므로, dp[3]은 -1
			if (dp[i - 2] < 1) dp[i] = -1;
			else {
				// 9 + 2 = 11
				// dp[9] = 3이므로, 2만큼 더 큰 11의 dp값은 2원을 추가하여 4가 됨
				dp[i] = dp[i - 2] + 1;
			}
		}
	}

	cout << dp[n];
}
