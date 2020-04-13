#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
vector<int> v[50001];
int lazy[200001]; bool tree[50001];
int a[50001], b[50001], cnt, bias;
void solve(int s) {
	a[s] = cnt++;
	for (auto a : v[s]) solve(a);
	b[s] = cnt;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, c, d; cin >> n >> m;;
		memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
		memset(tree, 0, sizeof(tree));
		for (int i = 0; i <= 50000; i++) v[i].clear();
		for (int i = 0; i < n - 2; i++) {
			cin >> c >> d;
			v[c].push_back(d);
		}
		solve(1);solve(2);
		for (int i = 0; i < b[1]; i++) tree[i] = 1;
		char x; int y, z;
		while (m--) {
			cin >> x;
			if (x == 'T') {
				cin >> y;
				for (int i = a[y]; i < b[y]; i++) tree[i] ^= 1;		
			}
			else {
				cin >> y >> z;
				bool q = tree[a[y]], r = tree[a[z]];
				if (q == r) cout << "Ally\n";
				else cout << "Enemy\n";
			}
		}
	}
}