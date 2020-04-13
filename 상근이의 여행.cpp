#include <iostream>
using namespace std;
int d[1001];
int find(int x) {
	if (x == d[x]) return x;
	return d[x] = find(d[x]);
}
bool setUnion(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return 0;
	d[y] = x;
	return 1;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) d[i] = i;
		int ans = 0;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			if (setUnion(a, b)) ans++;
		}
		cout << ans << "\n";
	}
}