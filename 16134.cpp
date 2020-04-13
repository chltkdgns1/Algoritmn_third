#include <iostream>
using namespace std;
typedef long long ll;
const ll inf = 1000000007;
ll solve(ll w) {
	ll t = inf - 2, c = w, ans = 1;
	for (int i = 0; i < 32; i++) {
		if (t & (1 << i)) ans *= c, ans %= inf;
		c *= c; c %= inf;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b; cin >> a >> b;
	ll r = 1, w = 1;
	for (int i = 0; i < b; i++) r *= a - i, r %= inf;
	for (int i = 0; i < b; i++) w *= b - i, w %= inf;
	cout << (r * solve(w)) % inf << "\n";
}