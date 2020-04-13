#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll dp[101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	dp[1] = 1; dp[2] = 2; dp[3] = 3;
	int n; cin >> n;
	for (int i = 4; i <= n; i++) {
		for (int j = 1; j <= i - 3; j++) {
			dp[i] = max(dp[i], max(dp[i - 1] + 1, dp[j] * (i - j - 1)));
		}
	}
	cout << dp[n] << "\n";
}