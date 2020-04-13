#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, s, e; cin >> n >> s >> e;
	vector <tuple<int, int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	sort(v.begin(), v.end());

	set <pair<ll, ll>> st;
	st.insert({ s,0 });
	for (int i = 0; i < n; i++) {
		int a, y1, y2;
		tie(a, y1, y2) = v[i];

		auto l = st.lower_bound({ y1, -1e18 });
		auto r = st.upper_bound({ y2, 1e18 });

		ll yd = 1e18, yh = 1e18;

		for (auto b = l; b != r; b++) {
			yd = min(yd, b->first - y1 + b->second);
			yh = min(yh, y2 - b->first + b->second);
		}
		st.erase(l, r);
		st.insert({ y1,yd });
		st.insert({ y2,yh });
	}

	ll ans = 1e18;

	for (auto a : st) ans = min(ans, a.second);
	cout << ans + e << "\n";

	vector <ll> et;
	for (auto a : st) {
		if (ans == a.second) et.push_back(a.first);
	}

	cout << et.size() << " ";
	for (auto a : et) cout << a << " ";
}