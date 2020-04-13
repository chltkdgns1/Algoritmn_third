#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
set<int> s[3001], e[3001];
map <pair<int, int>, int> mp;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, a, b; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		s[a].insert(b);
		e[b].insert(a);
	}

	for (int i = 1; i <= n; i++) {
		for (auto a : e[i]) {
			for (auto b : s[i]) {
				if (a == b) continue;
				mp[{a, b}]++;
			}
		}
	}

	long long res = 0;
	for (auto a : mp) res += ll(a.second * (a.second - 1)) / 2;
	cout << res << "\n";
}
