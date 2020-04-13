#include <iostream>
using namespace std;
int dp[1001][3][4];
int inf = 1000000;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	dp[n][0][0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int k = 0; k < 2; k++) {
			for (int z = 0; z < 3; z++) {
				if (dp[i + 1][k][z]) {
					int u = dp[i + 1][k][z];
					dp[i][k][0] += u; dp[i][k][z] %= inf;
					dp[i][k + 1][0] += u; dp[i][k + 1][z] %= inf;
					dp[i][k][z + 1] += u; dp[i][k][z + 1] %= inf;
				}
			}
		}
	}
	int ans = 0;
	for (int k = 0; k < 2; k++) {
		for (int z = 0; z < 3; z++) {
			ans += dp[0][k][z]; ans %= inf;
		}
	}
	cout << ans << "\n";
}