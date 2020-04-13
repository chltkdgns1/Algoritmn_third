#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;

typedef long long ll;

ll abse(ll a) {
	if (a < 0) return -a;
	else return a;
}

ll pow(ll a, int b) {
	ll res = 1;
	while (b) {res *= a;b--;}
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll x, y, ax, ay, bx, by; cin >> x >> y >> ax >> ay >> bx >> by;
	ll sx, sy, t; cin >> sx >> sy >> t;

	vector <pair<ll, ll>> v;
	v.push_back({ x,y });
	for (int i = 1; i < 64; i++) {
		ll dx = pow(ax, i)*x + bx * ((pow(ax, i) - 1) / (ax - 1));
		ll dy = pow(ay, i)*y + by * ((pow(ay, i) - 1) / (ay - 1));;
		if (dx >= 0 && dy >= 0 && dx <= 1e18 && dy <= 1e18) {
			if (v.back().first >= dx) break;
			v.push_back({ dx,dy });
		}
		else break;
	}

	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		ll dis = abse(v[i].first - sx) + abse(v[i].second - sy);
		ll td = t - dis;
		if (td < 0) continue;

		ll nowx = v[i].first, nowy = v[i].second;
		int cnt = 1;

		bool ch = 0;
		for (int k = i - 1; k >= 0; k--) {
			ll dist = abse(v[k].first - nowx) + abse(v[k].second - nowy);
			nowx = v[k].first, nowy = v[k].second;
			td -= dist;
			if (td >= 0) cnt++;
			else { ch = 1; break; }
		}

		ans = max(ans, cnt);
		if (ch) continue;

		for (int k = 0; k < v.size(); k++) {
			if (!i && !k) continue;
			ll dist = abse(v[k].first - nowx) + abse(v[k].second - nowy);
			nowx = v[k].first, nowy = v[k].second;
			td -= dist;
			if (td >= 0 && k >= i + 1) cnt++;
			else { ch = 1; break; }
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
}