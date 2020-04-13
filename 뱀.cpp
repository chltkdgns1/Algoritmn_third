#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
typedef long long ll;
class Data {
public:
	ll x, y, a, b;
};
vector<Data>v;
ll check(ll x, ll y, ll l,ll tx,ll ty) {
	ll a = abs(x - tx) + abs(ty - y);
	if (x > l) return a - (x - l) + 1;
	else if (x < -l) return a + x + l + 1;
	else if (y > l) return a - y + l + 1;
	else if(y < -l) return a + l + y + 1;
	return 0;
}
ll getCross(ll dir, ll x, ll y, ll s, ll e, ll l) {
	ll mx = max(x, s), my = max(y, e),nx = min(x, s), ny = min(y, e);
	ll ans = 1e18;
	if (!(dir % 2)) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i].y <= y && y <= v[i].b) {
				if (!dir && nx <= v[i].x && v[i].x <= mx) 
					if(abs(x - v[i].x)) ans = min(ans, abs(x - v[i].x));	
				if (dir == 2 && nx <= v[i].a && v[i].a <= mx) 
					if (abs(v[i].a - x)) ans = min(ans, abs(v[i].a - x));
			}
		}
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			if (v[i].x <= x && x <= v[i].a) {
				if (dir == 1 && ny <= v[i].y && v[i].y <= my) 
					if (abs(y - v[i].y)) ans = min(ans, abs(y - v[i].y));
				if (dir == 3 && ny <= v[i].b && v[i].b <= my) 
					if (abs(y - v[i].b)) ans = min(ans, abs(y - v[i].b));
			}
		}
	}
	return ans == 1e18 ? 0 : ans;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll l, n, x = 0, y = 0, dir = 0, ans = 0; cin >> l >> n;
	bool ch = 0;
	for (int i = 0; i <= n; i++) {
		ll a; char b;
		if(i != n ) cin >> a >> b;
		else a = l * 3;
		if (ch) continue; if (dir < 0) dir = 3;
		else dir %= 4;
		ll tx = x, ty = y;
		x += a * dx[dir], y += a * dy[dir];
		if (ll u = getCross(dir,tx, ty, x, y, l)) {
			ans += u; ch = 1;
			continue;
		}
		if (ll u = check(x, y, l,tx,ty)) { 
			ans += u; ch = 1;
			continue;
		}
		if (b == 'L') dir++; else dir--;	
		v.push_back({ min(x,tx),min(y,ty),max(tx,x),max(ty,y) });
		ans += a;
	}
	cout << ans << "\n";
}