#include <iostream>
#include<algorithm>
using namespace std;
int dp[1000001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, ans = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		dp[a] = dp[a - 1] + 1;
		ans = max(ans, dp[a]);
	}
	cout << n -ans << "\n";
}