#include <iostream>
#include <algorithm>
using namespace std;

int a[5010];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		k = min(k, --m);

		for (int i = 1; i <= n; i++) cin >> a[i];
		
		int res = 0;
		for (int i = 0; i <= k; i++) {
			int mx = 1e9;
			for (int z = 0; z <= m - k; z++) {
				mx = min(mx, max(a[i + z + 1], a[n - (k - i) - (m - k - z)]));
			}
			res = max(mx, res);
		}
		cout << res << "\n";
	}
}