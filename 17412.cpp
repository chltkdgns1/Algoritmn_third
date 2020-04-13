#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int c[401][401], f[401][401];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, p; cin >> n >> p;
	vector<int> v[401];
	for (int i = 0; i < p; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		c[a][b] = 1;
	}
	int sc = 1, sk = n, ans = 0;
	while (1) {
		int d[401]; memset(d, -1, sizeof(d));
		queue <int> q; q.push(sc);
		while (!q.empty()) {
			int nxt = q.front();
			q.pop();

			for (auto a : v[nxt]) {
				if (c[nxt][a] - f[nxt][a] > 0 && d[a] == -1) {
					d[a] = nxt;
					if (a == sk) break;
					q.push(a);
				}
			}
		}
		if (d[sk] == -1) break;
		int fw = 1e9;
		for (int i = sk; i != sc; i = d[i]) {
			fw = min(fw, c[d[i]][i] - f[d[i]][i]);
		}
		for (int i = sk; i != sc; i = d[i]) {
			f[d[i]][i] += fw;
			f[i][d[i]] -= fw;
		}
		ans += fw;
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			cout << f[i][k] << " ";
		}
		cout << "\n";
	}
	cout << ans << "\n";
	system("pause");
}