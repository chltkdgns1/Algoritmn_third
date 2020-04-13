#include <iostream>
using namespace std;
bool dp[1001];
int main() {
	int n; cin >> n;
	dp[1] = 1, dp[2] = 0, dp[3] = 1, dp[4] = 1;
	for (int i = 5; i <= n; i++) {
		dp[i] = (!dp[i - 1]) | (!dp[i - 3]) | (!dp[i - 4]);
	}
	cout << (dp[n] ? "SK" : "CY") << "\n";
}