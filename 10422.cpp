#include <iostream>
using namespace std;
typedef long long ll;
ll dp[5001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;

	dp[0] = dp[2] = 1;

	for (int i = 4; i <= 5000; i++) {
		for (int k = 2; k <= i; k += 2) {
			if(i - k >=0){
				dp[i] += dp[k - 2] * dp[i - k];
				dp[i] %= 1000000007;
			}
		}
	}
	while (t--) {
		int n; cin >> n;
		cout << dp[n] << "\n";
	}
}