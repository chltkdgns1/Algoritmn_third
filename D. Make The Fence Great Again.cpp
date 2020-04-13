#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll dp[300001][3], a[300001],b[300001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

		dp[0][0] = 0, dp[0][1] = b[0], dp[0][2] = 2*b[0];
		for (int i = 1; i < n; i++) {
			for (int k = 0; k < 3; k++) {
				dp[i][k] = 1e18;
				for (int z = 0; z < 3; z++) {
					if (a[i] + k != a[i - 1] + z) dp[i][k] = min(dp[i][k], dp[i - 1][z] + b[i] * k);
				}
			}
		}
		cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << "\n";
	}
}














/.1014