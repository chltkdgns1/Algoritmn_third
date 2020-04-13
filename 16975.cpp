#include<iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll bias, tree[400001], lazy[400001];
void exlazy(int n, int s, int e) {
	if (lazy[n]) {
		if (s != e) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		else tree[n] += lazy[n];
		lazy[n] = 0;
	}
}
void update(int n, int s, int e, int l, int r, ll k) {
	exlazy(n, s, e);
	if (e < l || r < s) return;
	if (l <= s && e <= r) {
		lazy[n] += k;
		return;
	}
	int m = (s + e) / 2;
	update(n * 2, s, m, l, r, k), update(n * 2 + 1, m + 1, e, l, r, k);
}
ll qurey(int n,int s,int e,int l) {
	exlazy(n, s, e);
	if (l < s || e < l) return 0;
	if (s == e) return tree[n];
	int m = (s + e) / 2;
	return qurey(n * 2, s, m, l) + qurey(n * 2 + 1, m + 1, e, l);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,a; cin >> n;
	for (bias = 1; bias < n; bias <<= 1);
	for (int i = 0; i < n; i++) {
		cin >> tree[bias + i];
	}
	int t; cin >> t;
	while (t--) {
		int a, s, e, k; cin >> a;
		if (a == 1) {
			cin >> s >> e >> k;
			s--, e--;
			update(1, 0, bias - 1, min(s,e),max(s,e), k);
		}
		else {
			cin >> s; 
			cout << qurey(1,0,bias-1,s - 1) << "\n";
		}
	}
}