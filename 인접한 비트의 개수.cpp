#include <iostream>
using namespace std;
int dp[101][101][2];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	dp[1][0][0] = dp[1][0][1] = 1;
	dp[2][1][1] = dp[2][0][1] = 1; dp[2][0][0] = 2;
	for (int i = 3; i <= 100; i++) {
		for (int k = 0; k < i; k++) {
			dp[i][k][0] = dp[i - 1][k][0] + dp[i - 1][k][1];
			dp[i][k][1] = dp[i - 1][k][0] + dp[i - 1][k - 1][1];
		}
	}
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		cout << dp[a][b][0] + dp[a][b][1] << "\n";
	}
}