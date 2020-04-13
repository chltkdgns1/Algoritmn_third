#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int check[205];
bool visit[205];
vector<int> v[205];
void add(int s, int e) {
	v[s].push_back(e);
	v[e].push_back(s);
}
bool solve(int s) {
	for (auto a : v[s]) {
		if (visit[a]) continue;
		visit[a] = 1;
		if (check[a] == -1 || solve(check[a])) {
			check[a] = s;
			return 1;
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		memset(check, -1, sizeof(check));
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < 205; i++) v[i].clear();
		int n, m; cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int s, e, a, b; cin >> s >> e >> a;
			for (int k = 0; k < a; k++) {
				cin >> b;
				for (int z = s; z < e; z++) add(z, b + 100);
			}
		}
		int cnt = 0, ans = -1;
		for (int i = 0; i < 100; i++) {
			if (v[i].size()) {
				memset(visit, 0, sizeof(visit));
				if (solve(i)) cnt++;
				if (cnt == n) {
					ans = i + 1;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
}