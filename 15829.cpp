#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1234567891;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n; char a;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a; ll u = a - 'a' + 1, r = 1;
		for (int k = 0; k < i; k++)  r *= 31, r %= mod;
		ans = (ans + (u * r) % mod) % mod;
	}
	cout << ans << "\n";
}