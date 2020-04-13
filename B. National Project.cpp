#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		ll a, b, c,d; cin >> a >> b >> c;
		d = (a + 1) / 2;
		cout << d + max(a - d, (d - 1) / b * c) << "\n";
	}
}