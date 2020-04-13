#include <iostream>
#include <algorithm>
using namespace std;
int a[5001], dp[5011][5011];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++) for (int k = 0; k <= n; k++) dp[i][k] = 1e9;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (dp[i][k] != 1e9) {
				dp[i + 1][k] = min(dp[i + 1][k], dp[i][k] + 1);
				dp[i][k + 1] = min(dp[i][k + 1], dp[i][k] + 1);
				if (a[i + 1] == a[n - k]) 
					dp[i + 1][k + 1] = min(dp[i + 1][k + 1], dp[i][k]);
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i <= n; i++) {
		for (int k = 0; k <= n; k++) {
			if (i + k >= n) ans = min(ans, dp[i][k]);
		}
	}
	cout << ans << "\n";
}