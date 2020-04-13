#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll dp[101][101];
int p[27];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, k; cin >> n >> k;
	char s[101]; cin >> s + 1;

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int k = 1; k <= i; k++) {
			dp[i][k] = dp[i - 1][k] + dp[i - 1][k - 1];
			if (p[s[i] - 'a']) dp[i][k] -= dp[p[s[i] - 'a'] - 1][k - 1];
		}
		p[s[i] - 'a'] = i;
	}

	ll ans = 0;
	for (int i = n; i >= 0; i--) {
		ll t = min(k, dp[n][i]);
		k -= t;
		ans += (n - i)*t;
		if (!k) break;
	}
	if (k) ans = -1;
	cout << ans << "\n";
}