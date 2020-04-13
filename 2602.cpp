#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int dp[101][21][2];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b[2]; cin >> a >> b[0] >> b[1];
	int n = b[0].length(), m = a.length();
	for (int z = 0; z < m; z++) {
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < 2; k++) {
				if (b[k][i] == a[z]) {
					if (z == 0) {
						dp[i][z][k] = 1;
						continue;
					}
					int t = !k;
					for (int q = 0; q < i; q++) {
						dp[i][z][k] += dp[q][z - 1][t];
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 2; k++) {
			ans += dp[i][m - 1][k];
		}
	}
	cout << ans << "\n";
}