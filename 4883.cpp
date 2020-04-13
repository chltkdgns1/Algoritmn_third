#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll dp[100001][4];
int map[100001][4];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int cs = 1;
	while (1) {
		int n; cin >> n;
		if (!n) break;
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= 3; k++) {
				cin >> map[i][k];
				dp[i][k] = 1e18;
			}
		}
		dp[1][2] = map[1][2];
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= 3; k++) {
				if (dp[i][k] != 1e18) {
					if (i + 1 <= n && k - 1 >= 1)
						dp[i + 1][k - 1] = min(dp[i + 1][k - 1], dp[i][k] + map[i + 1][k - 1]);
					if (i + 1 <= n)
						dp[i + 1][k] = min(dp[i + 1][k], dp[i][k] + map[i + 1][k]);
					if (i + 1 <= n && k + 1 <= 3)
						dp[i + 1][k + 1] = min(dp[i + 1][k + 1], dp[i][k] + map[i + 1][k + 1]);
					if (k + 1 <= 3)
						dp[i][k + 1] = min(dp[i][k + 1], dp[i][k] + map[i][k + 1]);
				}
			}
		}
		cout << cs++<<". "<<dp[n][2] << "\n";
	}
}