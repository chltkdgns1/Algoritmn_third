#include <iostream>
#include <math.h>
using namespace std;

typedef long long ll;
ll tree[4000001], lazy[4000001], t;

void init(int i, int s) {
	i += t;
	do { tree[i] += s; } while (i >>= 1);
}

void lazy_cal(int n, int s, int e) {
	tree[n] += lazy[n] * (e - s + 1);
	if (lazy[n]) {
		if (s != e) {
			lazy[2 * n] += lazy[n];
			lazy[2 * n + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

ll update(int s, int e, int n, int l, int r, ll q) {
	lazy_cal(n, s, e);
	if (e < l || r < s) return tree[n];
	if (l <= s && e <= r) {
		tree[n] += q * (e - s + 1);
		if (s != e) {
			lazy[2 * n] += q;
			lazy[2 * n + 1] += q;
		}
		return tree[n];
	}

	int m = (s + e) / 2;
	return tree[n] = update(s, m, n * 2, l, r, q) + update(m + 1, e, n * 2 + 1, l, r, q);
}

ll find(int s, int e, int n, int l, int r) {
	lazy_cal(n, s, e);
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[n];
	int m = (s + e) / 2;
	return find(s, m, n * 2, l, r) + find(m + 1, e, n * 2 + 1, l, r);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, m, k, a; cin >> n >> m >> k;
	int h = ceil(log2(n));
	t = 1 << h;
	for (int i = 0; i < n; i++) cin >> a, init(i, a);

	ll x, y, z, w;
	for (int i = 0; i < m + k; i++) {
		cin >> x >> y >> z;
		if (x == 1) {
			cin >> w;
			update(0, t - 1, 1, y - 1, z -1, w);
		}
		else cout << find(0, t - 1, 1, y - 1, z -1) << "\n";
	}
}