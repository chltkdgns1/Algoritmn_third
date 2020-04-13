#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 1000	
int c[2010][2010], f[2010][2010], sk = 2003, sc = 2001, nd = 2002;
vector<int> v[2010];
void add(int s, int e, int k) {
	v[s].push_back(e);
	v[e].push_back(s);
	c[s][e] = k;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k, a, t; cin >> n >> m >> k;
	int ans = 0;
	add(sc, nd, k);
	for (int i = 1; i <= m; i++) add(i + MAX, sk, 1);
	for (int i = 1; i <= n; i++) {
		cin >> t;
		add(nd, i, min(k, t)); add(sc, i, 1);
		for (int k = 0; k < t; k++) {
			cin >> a; add(i, a + MAX, 1);
		}
	}
	while (1) {
		int d[2010]; memset(d, -1, sizeof(d));
		queue<int> q; q.push(sc);
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto a : v[t]) {
				if (c[t][a] - f[t][a] > 0 && d[a] == -1) {
					d[a] = t;
					if (a == sk) break;
					q.push(a);
				}
			}
		}
		if (d[sk] == -1) break;
		int flow = 1e9;
		for (int i = sk; i != sc; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		for (int i = sk; i != sc; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		ans += flow;
	}
	cout << ans << "\n";
}