#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][501], a[101];
vector <int> v[101];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i], dp[i][0] = a[i];

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}

	for (int i = 1; i <= 500; i++) {
		for (int k = 1; k <= n; k++) {
			dp[k][i] = 1e9;
			for (auto a : v[k]) {
				dp[k][i] = min(dp[k][i], dp[a][i - 1]);
			}
		}
	}
	int k; cin >> k;
	while (k--) {
		int a, b; cin >> a >> b;
		if (dp[a][b] == 1e9) cout << -1 << "\n";
		else cout << dp[a][b] << "\n";
	}
}