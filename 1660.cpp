#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll dp[300001], dq[300001];
int ans[300001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<ll> v;
	int n; cin >> n;
	dp[1] = dq[1] = 1;
	v.push_back(1);
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + i;
		dq[i] = dq[i - 1] + dp[i];
		if (dq[i] > n) break;
		v.push_back(dq[i]);
	}
	for (int i = 0; i < n; i++) ans[i] = 1e9;
	for (int i = n; i > 0; i--) {
		for (int k = 0; k < v.size(); k++) {
			if (ans[i] != 1e9 && i - v[k] >= 0) 
				ans[i - v[k]] = min(ans[i - v[k]], ans[i] + 1);		
		}
	}
	cout << ans[0] << "\n";
}