#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
ll dp[101][101][101];
ll mod = 1000000007;
ll solve(int n, int r, int l) {
	if (n < r + l - 1 || !r || !l) return 0;
	if (n == 1) return 1;
	ll &ref = dp[n][r][l];
	if (ref != -1) return ref;
	ref = 0;
	return ref = ((solve(n - 1, r, l) *(n - 2) % mod + solve(n - 1, r - 1, l)) % mod + solve(n - 1, r, l - 1)) % mod;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c; cin >> a >> b >> c;
	memset(dp, -1, sizeof(dp));
	cout << solve(a, b, c) << "\n";
}