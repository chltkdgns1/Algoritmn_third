#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
class Data {
public:
	ll g, x, y;
};
Data exclid(ll a, ll b) {
	if (!b) return { a,1,0 };
	Data d = exclid(b, a%b);
	return { d.g,d.y,d.x - a / b * d.y };
}
ll ceil(ll a, ll b) {
	if (a >= 0) return (a + b - 1) / b;
	return a / b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		Data d = exclid(a, b);

		if (d.g != 1) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		ll t = min(ceil(-d.x, b), ceil(d.y, a)) - 1;
		if (d.y - 1e9 > a*t) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << d.y - t * a << "\n";
	}
}