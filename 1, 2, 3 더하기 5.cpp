#include <iostream>
using namespace std;
const int mod = 1e9 + 9;
typedef long long ll;
ll dp[100001][4];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	dp[3][1] = dp[3][2] = dp[3][3] = dp[1][1] = dp[2][2] = 1;
	for (int i = 4; i <= 100000; i++) {
		for (int k = 1; k <= 3; k++) {
			if (k == 1) dp[i][k] = (dp[i - k][2] + dp[i - k][3]) % mod;
			else if (k == 2) dp[i][k] = (dp[i - k][1] + dp[i - k][3]) % mod;
			else dp[i][k] = (dp[i - k][1] + dp[i - k][2]) % mod;
		}
	}
	while (t--) {
		int n; cin >> n;
		cout << ((dp[n][1] + dp[n][2]) % mod + dp[n][3])%mod << "\n";
	}
}