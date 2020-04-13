#include <iostream>
using namespace std;
int dp[1025][1025];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m,a; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			cin >> a;
			dp[i][k] = dp[i - 1][k] + dp[i][k - 1] - dp[i - 1][k - 1] + a;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c, d; cin >> b >> a >> d >> c;
		cout << dp[d][c] + dp[b - 1][a - 1] - dp[d][a - 1] - dp[b - 1][c] << "\n";
	}
}