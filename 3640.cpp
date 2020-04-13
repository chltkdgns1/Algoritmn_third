#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int f[2002][2002], c[2002][2002], cost[2002][2002], sc = 1, sk = 2001;
bool inq[2002];
vector<int> v[2002];
void add(int s, int e, int k,int t) {
	v[s].push_back(e);
	v[e].push_back(s);
	c[s][e] = k; cost[s][e] = t, cost[e][s] = -t;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; 
	while (cin >> n >> m) {
		memset(f, 0, sizeof(f)), memset(c, 0, sizeof(c));
		memset(inq, 0, sizeof(inq));
		memset(cost, 0, sizeof(cost));
		for (int i = 1; i <= 2001; i++) v[i].clear();
		sk = n;
		for (int i = 2; i <= n; i++) add(i, i + 1000, 1, 0);
		for (int i = 1; i <= m; i++) {
			int a, b, c; cin >> a >> b >> c;
			add(a + 1000, b, 1, c);
		}
		add(sc, sc + 1000, 2, 0);
		int ans = 0,flw = 0;
		while (1) {
			int pv[2002]; memset(pv, -1, sizeof(pv));
			int dist[2002]; for (int i = 1; i <= 2001; i++) dist[i] = 1e9;
			queue<int>q; q.push(sc);
			inq[sc] = 1;
			dist[sc] = 0;
			while (!q.empty()) {
				int nxt = q.front();
				q.pop();
				inq[nxt] = 0;
				for (auto a : v[nxt]) {
					if (dist[a] > dist[nxt] + cost[nxt][a] && c[nxt][a] - f[nxt][a] > 0) {
						dist[a] = dist[nxt] + cost[nxt][a];
						pv[a] = nxt;
						if (!inq[a]) {
							inq[a] = 1;
							q.push(a);
						} 
					}
				}
			}
			if (pv[sk] == -1) break;
			int fw = 1e9;
			for (int i = sk; i != sc; i = pv[i]) {
				fw = min(fw, c[pv[i]][i] - f[pv[i]][i]);
			}
			for (int i = sk; i != sc; i = pv[i]) {
				ans += cost[pv[i]][i];
				f[pv[i]][i] += fw;
				f[i][pv[i]] -= fw;
			}
			flw += fw;
		}
		cout << ans << "\n";
	}
}