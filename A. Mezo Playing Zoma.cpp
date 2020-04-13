#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll sum = 0, res = 0, l = 0, r = 0, a;
		for (int i = 1; i <= n; i++) {
			cin >> a; sum += a;
			if (sum > res) res = sum, r = i;
			if (sum <= 0) sum = 0, l = i;
		}

		if (r == n && !l) cout << "YES\n";
		else cout << "NO\n";
	}
}