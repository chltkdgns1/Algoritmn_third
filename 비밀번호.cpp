#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int dp[8][1 << 10], u;
int solve(int idx, int t) {
	if (!idx && ((t & u) == u)) return 1;
	if (!idx) return 0;

	int &ref = dp[idx][t];
	if (ref != -1) return ref;
	ref = 0;
	for (int i = 0; i <= 9; i++) ref += solve(idx - 1, (t | (1 << i)));
	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		u |= (1 << a);
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(n, 0) << "\n";
}