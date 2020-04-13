#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
vector <ll> a, b;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, ta, tb, k,t; cin >> n >> m >> ta >> tb >> k;
	for (int i = 0; i < n; i++) cin >> t, a.push_back(t);
	for (int i = 0; i < m; i++) cin >> t, b.push_back(t);

	if (n <= k || m <= k) {
		cout << -1;
		return 0;
	}
	ll res = 0;
	for (int i = 0; i < n; i++) {
		ll t = k - i, u = a[i] + ta;
		if (t < 0) break;
		int idx = lower_bound(b.begin(), b.end(), u) - b.begin();
		if (idx + t >= m) {
			cout << -1;
			return 0;
		}
		res = max(res, ll(b[idx + t] + tb));
	}
	cout << res << "\n";
}