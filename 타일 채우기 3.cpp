#include <iostream>
#include <string.h>
#define mod  1000000007
using namespace std;
typedef long long ll;
ll dp[1000001][3];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	dp[1][0] = 2, dp[2][0] = 7, dp[1][1] = dp[1][2] = 1;
	dp[2][1] = dp[2][2] = 3;

	for (int i = 3; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] * 2 % mod + ((dp[i - 2][0] +
			dp[i - 1][1]) % mod + dp[i - 1][2]) % mod) % mod;

		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
	}
	cout << dp[n][0] << "\n";
}