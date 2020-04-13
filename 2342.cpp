#include <iostream>
#include <algorithm>
using namespace std;
int dp[5][5][100001];
int cal(int a, int b) {
	if (a == b) return 1;
	if (!a) return 2;
	if (a % 2 == b % 2) return 4;
	return 3;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			for (int z = 0; z <= 100000; z++) {
				dp[i][k][z] = 1e9;
			}
		}
	}
	dp[0][0][0] = 0; int idx = 1;
	while (1) {
		int n; cin >> n;
		if (!n) break;
		bool ch = n % 2;
		for (int i = 0; i < 5; i++) {
			for (int k = 0; k < 5; k++) {
				if (dp[i][k][idx - 1] != 1e9) {
					dp[n][k][idx] = min(dp[n][k][idx], dp[i][k][idx - 1] + cal(i,n));
					dp[i][n][idx] = min(dp[i][n][idx], dp[i][k][idx - 1] + cal(k,n));
				}
			}
		}
		idx++;
	}
	int ans = 1e9;
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			ans = min(ans, dp[i][k][idx - 1]);
		}
	}
	cout << ans << "\n";
}