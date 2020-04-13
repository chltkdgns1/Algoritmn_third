#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int dp[21][21][21];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, b; cin >> n >> a >> b;
	int m; cin >> m;
	vector<int> v(m + 1);
	for (int i = 1; i <= n; i++)
		for (int k = 1; k <= n; k++)
			for (int z = 0; z <= m; z++)
				dp[i][k][z] = 1e9;
	for (int i = 1; i <= m; i++) cin >> v[i];
	dp[a][b][0] = 0;
	for (int i = 1; i <= m; i++) {
		for (int k = 1; k <= n; k++) {
			for (int z = 1; z <= n; z++) {
				if (dp[k][z][i - 1] != 1e9) {
					int u = v[i];
					dp[u][z][i] = min(dp[u][z][i], dp[k][z][i - 1] + abs(k - u));
					dp[k][u][i] = min(dp[k][u][i], dp[k][z][i - 1] + abs(z - u));
				}
			}
		}
	}
	int ans = 1e9;
	for (int k = 1; k <= n; k++) {
		for (int z = 1; z <= n; z++) {
			ans = min(ans, dp[k][z][m]);
		}
	}
	cout << ans << "\n";
}