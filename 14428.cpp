#include <iostream>
#include <vector>
using namespace std;
#define xx first
#define yy second
vector<pair<int, int>> tree;
int sz;
void init(int a, int b) {
	int u = a + sz;
	tree[u] = { a,b };
	while (u >>= 1) {
		tree[u] = tree[u << 1].yy <= tree[u << 1 | 1].yy ? tree[u << 1]
			: tree[u << 1 | 1];
	}
}
int qurey(int l, int r) {
	l += sz, r += sz;
	pair<int, int> ans = { 1e9,1e9 };
	while (l < r) {
		if (l & 1) {
			if (ans.yy > tree[l].yy) ans = tree[l];
			else if (ans.yy == tree[l].yy) ans = ans.xx > tree[l].xx ? tree[l] : ans;
			l++;
		}
		if (!(r & 1)) {
			if (ans.yy > tree[r].yy) ans = tree[r];
			else if (ans.yy == tree[r].yy) ans = ans.xx > tree[r].xx ? tree[r] : ans;
			r--;
		}
		r >>= 1, l >>= 1;
	}
	if (l == r) {
		if (ans.yy > tree[l].yy) ans = tree[l];
		else if (ans.yy == tree[l].yy) ans = ans.xx > tree[l].xx ? tree[l] : ans;
	}
	return ans.first;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (sz = 1; sz < n; sz <<= 1);
	tree.resize((sz << 1) + 1);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		init(i, a);
	}
	int m; cin >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) init(b - 1, c);
		else {
			cout << qurey(b - 1, c - 1) + 1 << "\n";
		}
	}
}