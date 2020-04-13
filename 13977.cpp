#include <iostream>
using namespace std;
typedef long long ll;
ll dp[4000001];
const ll inf = 1000000007;
ll solve(ll w) {
	ll t = inf - 2, c = w, ans = 1;
	for (int i = 0; i < 32; i++) {
		if (t & (1 << i)) ans *= c, ans %= inf;
		c *= c; c %= inf;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	dp[1] = 1;
	for (int i = 2; i <= 4000000; i++) {
		dp[i] = dp[i - 1]*i;
		dp[i] %= inf;
	}
	while (t--) {
		int a, b; cin >> a >> b;
		if (!b || a == b) cout << 1 << "\n";
		else cout << (dp[a] * solve((dp[b] * dp[a - b]) % inf)) % inf << "\n";
	}
}