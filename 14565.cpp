#include <iostream>
using namespace std;
typedef long long ll;
class Data {
public:
	ll g, x, y;
};
Data uclid(ll a, ll b) {
	if (!b) return {a,1,0 };
	Data d = uclid(b, a%b);
	return { d.g,d.y,d.x - a / b * d.y };
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, a; cin >> n >> a;
	Data d = uclid(a, n);
	while (d.x < 0) d.x += n;
	cout << n - a << " " << (d.g != 1 ? -1 : d.x);
	system("pause");
}
