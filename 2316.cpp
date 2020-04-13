#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int c[801][801], f[801][801];
vector<int> v[801];
void add(int s, int e, int k, bool t) {
	v[s].push_back(e);
	v[e].push_back(s);
	if (!t) c[e][s] = k;
	c[s][e] = k;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, p; cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		if (i <= 2) add(i, i + 400, 1e9, 1);
		else add(i, i + 400, 1, 1);
	}
	for (int i = 0; i < p; i++) {
		int a, b; cin >> a >> b;
		add(a + 400, b, 1, 1);
		add(b + 400, a, 1, 1);
	}
	int sc = 1, sk = 2, ans = 0;
	while (1) {
		int d[801]; memset(d, -1, sizeof(d));
		queue <int> q; q.push(sc);
		while (!q.empty()) {
			int nxt = q.front();
			q.pop();
			bool k = 0;
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
	cout << ans << "\n";
}