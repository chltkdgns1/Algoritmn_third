#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 0; i <= n; i++) dp[i] = 1e9;
	dp[n] = 0;
	for (int i = n; i > 0; i--) {
		if (dp[i] != 1e9) {
			for (int k = 1; k <= n; k++) {
				if (i - k >= 0) {	
					dp[i - k] = min(dp[i - k], dp[i] + v[k]);
				}
			}
		}
	}
	cout << dp[0] << "\n";
}