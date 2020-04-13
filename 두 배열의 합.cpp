#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t, n, m; cin >> t >> n;
	vector <ll> a(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	cin >> m;
	vector <ll> b(m + 1, 0);
	for (int i = 1; i <= m; i++) cin >> b[i], b[i] += b[i - 1];

	vector<ll> x, y;
	for (int i = 0; i < n; i++) {
		for (int k = i + 1; k <= n; k++) x.push_back(a[k] - a[i]);
	}
	for (int i = 0; i < m; i++) {
		for (int k = i + 1; k <= m; k++) y.push_back(b[k] - b[i]);
	}

	sort(y.begin(), y.end());
	ll ans = 0;
	for (int i = 0; i < x.size(); i++) {
		auto a = lower_bound(y.begin(), y.end(), t - x[i]);
		auto b = upper_bound(y.begin(), y.end(), t - x[i]);
		ans += b - a;
	}
	cout << ans << "\n";
}