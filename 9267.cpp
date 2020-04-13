#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
class Data {
public:
	ll g, x, y;
};
Data uclid(ll a, ll b) {
	if (!b) return { a, 1,0 };
	Data d = uclid(b, a%b);
	return { d.g,d.y,d.x - a / b * d.y };
}
bool solve(ll a, ll b, ll s) {
	if (!a && !b) return !s;
	if (!a) return s % b == 0;
	if (!b) return s % a == 0;
	if (a == s || b == s) return 1;
	Data d = uclid(a, b);
	if (s % d.g) return 0;
	ll z = abs(b / d.g);
	ll x = (d.x % z) *(s / d.g % z) % z;
	if (x < 0) x += z;
	ll y = (s - a * x) / b;
	while (y > 0) {
		if (uclid(x, y).g == 1) return true;
		x += b / d.g;
		y -= a / d.g;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b, s; cin >> a >> b >> s;
	if (solve(a, b, s)) cout << "YES\n";
	else cout << "NO\n";
	system("pause");
}