#include <iostream>
#include <algorithm>

using namespace std;

int t, n;
long long dp[101] = { 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;
	dp[6] = 3; dp[7] = 4; dp[8] = 5; dp[9] = 7; dp[10] = 9;

	for (int i = 11; i < 101; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}