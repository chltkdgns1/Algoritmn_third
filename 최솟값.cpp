#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> tree;
int sz;
void init(int a, int b) {
	a += sz;
	tree[a] = b;
	while (a >>= 1) 
		tree[a] = min(tree[2 * a], tree[2 * a + 1]);
}
int qurey(int s, int e) {
	s += sz, e += sz;
	int ans = 1e9;
	while (s <= e) {
		if (s & 1) ans = min(ans, tree[s++]);
		if (!(e & 1)) ans = min(ans, tree[e--]);
		s >>= 1, e >>= 1;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (sz = 1; sz < n; sz <<= 1);
	tree.resize((sz << 1));
	for (int i = 1; i <= n; i++) {
		int a; cin >> a; init(i, a);
	}
	while (m--) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		cout << qurey(a, b) << "\n";
	}
}