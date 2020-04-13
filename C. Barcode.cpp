#include <iostream>
#include <algorithm>
using namespace std;

int p[1010], dp[1010][2];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, x, y;	char a; cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> a;
			p[k + 1] += a == '#' ? 1 : 0;
		}
	}

	for (int i = 1; i <= m; i++) p[i] += p[i - 1];

	for (int i = 1; i <= m; i++) 
		for (int k = 0; k < 2; k++) dp[i][k] = 1e9;

	dp[0][0] = dp[0][1] = 0;
	for (int i = 0; i <= m; i++) {
		for (int k = x; k <= y; k++) {
			if (i + k > m) break;
			dp[i + k][1] = min(dp[i + k][1], dp[i][0] + n*k - (p[i + k] - p[i]));
			dp[i + k][0] = min(dp[i + k][0], dp[i][1] + p[i + k] - p[i]);
		}
	}
	cout << min(dp[m][0], dp[m][1]);
}