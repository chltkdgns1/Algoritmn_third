#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
using namespace std;

typedef pair<int, int> p;

multiset<int> s;
vector<p> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int c, n; cin >> c >> n;
	v.resize(n);

	for (int i = 0; i < c; i++) {
		int t; cin >> t; s.insert(t);
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
	}

	sort(all(v), [](p a, p b) {
		if (a.y != b.y) return a.y < b.y;
		return a.x < b.x;
	});

	int ans = 0;
	for (auto i : v) {
		auto it = s.lower_bound(i.x);
		if (it != s.end() && *it <= i.y) {
			ans++; s.erase(it);
		}
	}
	cout << ans;
}