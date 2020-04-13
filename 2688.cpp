#include <iostream>
using namespace std;
typedef long long ll;
ll dp[65][10];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i <= 9; i++) dp[1][i] = 1;
	for (int i = 2; i <= 64; i++) {
		for (int k = 0; k <= 9; k++) {
			for (int z = 0; z <= k; z++) {
				dp[i][k] += dp[i - 1][z];
			}
		}
	}
	int t; cin >> t;
	while (t--) {
		ll a,ans =0; cin >> a; 
		for (int i = 0; i <= 9; i++) ans += dp[a][i];
		cout << ans << "\n";
	}
}