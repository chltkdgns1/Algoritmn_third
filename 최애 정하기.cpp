#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <string.h>
using namespace std;
vector<int> v[1001];
int mping[2010], check[2010];
bool solve(int idx) {
	for (auto a : v[idx]) {
		if (!check[a]) {
			check[a] = 1;
			if (!mping[a] || solve(mping[a])) {
				mping[a] = idx;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	unordered_map <string, int> girl;
	for (int i = 1; i <= m; i++) {
		string s; cin >> s;
		girl[s] = i + 1000;
	}
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		while (t--) {
			string a; cin >> a;
			v[i].push_back(girl[a]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		bool t = solve(i);
		ans += t;
	}
	if (ans == n) cout << "YES";
	else cout << "NO\n" << ans;
}