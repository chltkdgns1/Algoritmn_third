#include <iostream>
#include <string.h>
using namespace std;

typedef long long ll;
ll dp[31][31]; int n;

ll solve(int a, int b) {
	if (a == n || a == b) return 1;
	ll &ref = dp[a][b];
	if (ref != -1) return ref;
	ref = 0;

	for (int i = 0; i <= a; i++) {
		if (b + i > a) break;
		ref += solve(a + 1, b + i);
	}
	return ref;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		cin >> n;
		if (!n) break;
		memset(dp, -1, sizeof(dp));
		cout << solve(1, 0) << "\n";
	}
}