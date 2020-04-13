#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

typedef long long ll;

ll trr[800009];
ll lzy[800009];

void upd(ll n, ll s,ll e, ll l,ll r, ll x) {
	if (s > r || e<l || s>e)
		return;
	if (l <= s && e <= r) {
		trr[n] += x; lzy[n] += x;
		return;
	}
	if (lzy[n]) {
		lzy[n << 1] += lzy[n]; lzy[n << 1 | 1] += lzy[n];
		trr[n << 1] += lzy[n]; trr[n << 1 | 1] += lzy[n];
		lzy[n] = 0;
	}
	int m = (s + e) >> 1;
	upd(n << 1, s, m, l, r, x); upd(n << 1 | 1, m + 1, e, l, r, x);
	trr[n] = min(trr[n << 1], trr[n << 1 | 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(trr, 0, sizeof(trr));
	memset(lzy, 0, sizeof(lzy));
	int n; cin >> n;
	ll a[200001], b[200001], p[200001];
	for (int i = 1; i <= n; i++) {
		cin >> p[i]; b[p[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll s = 0, ans = min(a[1], a[n]);
	for (int i = 1; i <= n; i++) {
		s += a[b[i]];
		upd(1, 1, n, i, i, s);
	}
	for (int i = 1; i < n; i++) {
		upd(1, 1, n, p[i], n, -a[i]);
		upd(1, 1, n, 1, p[i] - 1, a[i]);
		ans = min(ans, trr[1]);
	}
	cout << ans << "\n";
}