#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

pair<int, int> v[101];
int n, m, dp[101][10001]; // ÀÎµ¦½º ºñ¿ë
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int  u = 0;
	for (int i = 1; i <= n; i++) cin >> v[i].first;
	for (int i = 1; i <= n; i++) cin >> v[i].second, u += v[i].second;
	
	memset(dp, -1, sizeof(dp));
	dp[1][0] = 0, dp[1][v[1].second] = v[1].first;
	int ans = 1e9;
	if (v[1].first >= m) ans = v[1].second;

	for (int i = 2; i <= n; i++) {
		for (int k = 0; k <= u; k++) {
			int u = i - 1;
			if (dp[u][k] != -1) {
				dp[i][k + v[i].second] = dp[u][k] + v[i].first;
				dp[i][k] = max(dp[i][k],dp[u][k]);
				if (dp[i][k + v[i].second] >= m) ans = min(ans, k + v[i].second);
			}
		}
	}
	cout << ans << "\n";
}