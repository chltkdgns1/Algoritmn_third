#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[21][101], a[21], b[21];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	memset(dp, -1, sizeof(dp));
	dp[0][100] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= 100; k++) {
			if (dp[i - 1][k] != -1) {
				int t = k - a[i];
				if (t > 0) {
					dp[i][t] = max(dp[i][t], dp[i - 1][k] + b[i]);
					ans = max(ans, dp[i][t]);
				}
				dp[i][k] = max(dp[i][k],dp[i - 1][k]);
				ans = max(ans, dp[i][k]);
			}
		}
	}
	cout << ans << "\n";
}