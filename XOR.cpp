#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll tree[2000000], lazys[2000000];
ll sz;
void init(int s, int t) {
	s += sz;
	do {
		tree[s] ^= t;
	} while (s >>= 1);
}
void lazy(int s,int e,int n) {
	if (lazys[n]) {
		if ((e - s + 1) % 2) tree[n] ^= lazys[n];
		if (s != e) {
			lazys[2 * n] ^= lazys[n];
			lazys[2 * n + 1] ^= lazys[n];
		}
		lazys[n] = 0;
	}
}
void update(int s, int e,int n, int l, int r, int q) {
	lazy(s, e, n);
	if (e < l || r < s) return;
	if (l <= s && e <= r) {
		if ((e - s + 1) % 2) tree[n] ^= q;
		if (s != e) {
			lazys[2 * n] ^= q;
			lazys[2 * n + 1] ^= q;
		}
		return;
	}
	int m = (s + e) / 2;
	update(s, m, n * 2, l, r, q) , update(m + 1, e, n * 2 + 1, l, r, q);
	tree[n] = tree[n * 2] ^ tree[n * 2 + 1];
}
int qurey(int s, int e, int n, int l, int r) {
	lazy(s, e, n);
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[n];
	int m = (s + e) / 2;
	return (qurey(s, m, n * 2, l, r) ^ qurey(m + 1, e, n * 2 + 1, l, r));
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n; cin >> n;
	for (sz = 1; sz < n; sz <<= 1);
	for (int i = 0; i < n; i++) {
		int a; cin >> a; init(i, a);
	}
	ll m,a,b,c,d; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (c < b) swap(b, c);
		if (a == 1) {
			cin >> d;
			update(0, sz - 1, 1, b, c, d);
		}
		else cout << qurey(0, sz - 1, 1, b, c) << "\n";
	}
}