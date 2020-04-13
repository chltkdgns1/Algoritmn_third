#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int dp[10001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, n; cin >> t >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	dp[t] = 1;
	for (int i = 0; i < v.size(); i++) {
		for (int k = 1; k <= t; k++) {
			if (dp[k]) {
				for (int z = 1; z <= v[i].second; z++) {
					if (k - v[i].first*z >= 0) dp[k - v[i].first*z] += dp[k];
					else break;
				}
			}
		}
	}
	cout << dp[0] << "\n";
}