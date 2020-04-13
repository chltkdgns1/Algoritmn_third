#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[200001], b[200001];

void solve(ll &a, ll &b, ll &c,int n,int m,ll *q,ll *r,bool ch) {
	for (int i = 0; i <= n;) {
		ll x = 0, y = 0;
		int idx = lower_bound(q, q + m, r[i]) - q;
		x += i * 2 + (n - i) * 3;
		y += idx * 2 + (m - idx) * 3;
		if (!ch) {
			if (c < x - y) c = x - y, a = x, b = y;
			else if (c == x - y && a < x) a = x, b = y;
		}
		else {
			if (c < y - x) c = y - x, a = y, b = x;
			else if (c == y - x && a < y) a = y, b = x;
		}
		if (i == n) break;
		i = upper_bound(r, r + n, r[i]) - r;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a, a + n), sort(b, b + m);
	a[n] = a[n - 1] + 1, b[m] = b[m - 1] + 1;
	ll aa = 0, bb = 0, cc = -1e18;
	solve(aa, bb, cc, n,m, b, a,0);
	solve(aa, bb, cc, m,n, a, b,1);
	cout << aa << ":" << bb << "\n";
}