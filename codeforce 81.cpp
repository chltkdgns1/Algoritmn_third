#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a; cin >> n >> m;
	vector <vector<int>> v(n);
	vector <int> e(n);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) cin >> a, v[i].push_back(--a);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) e[k] = k + n;
		for (int k = 0; k < n; k++) {
			if (v[k][i] % m == i && v[k][i] < n*m) {
				e[(k - (v[k][i] / m) + n) % n]--;
			}
		}
		int s = 1e9;
		for (int k = 0; k < n; k++) s = min(s, e[k]);
		ans += s;
	}
	cout << ans << "\n";
}