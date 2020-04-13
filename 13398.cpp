#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001][2];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int>v(n + 1);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	if (v[0] >= 0) dp[0][0] = v[0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = (dp[i - 1][0] + v[i]) >= 0 ? dp[i - 1][0] + v[i] : (v[i] >= 0 ? v[i] : 0);
		dp[i][1] = max(dp[i - 1][0], max(0, dp[i - 1][1] + v[i]));
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	if (!ans) {
		ans = -1e9;
		for (int i = 0; i < n; i++) ans = max(ans, v[i]);
	}
	cout << ans << "\n";
}