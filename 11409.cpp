#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int f[810][810], c[810][810], dist[810];
int cost[810][810], sc = 805, sk = 806;
bool visit[810];
vector<int> v[810];
void add(int s, int e, int k) {
	v[s].push_back(e);
	v[e].push_back(s);
	c[s][e] = k;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) add(sc, i, 1);
	for (int i = 1; i <= m; i++) add(i + 400, sk, 1);
	for (int i = 1; i <= n; i++) {
		int a, b, c; cin >> a;
		for (int k = 0; k < a; k++) {
			cin >> b >> c;
			add(i, b + 400, 1);
			cost[i][b + 400] = -c, cost[b + 400][i] = c;
		}
	}
	int fw = 0, ct = 0;;
	while (1) {
		queue <int> q;
		int pv[810]; memset(pv, -1, sizeof(pv));
		q.push(sc); visit[sc] = 1;
		for (int i = 1; i < 810; i++) dist[i] = 1e9;
		dist[sc] = 0;
		while (!q.empty()) {
			int nxt = q.front(); q.pop();
			visit[nxt] = 0;
			for (auto a : v[nxt]) {
				int t = dist[nxt] + cost[nxt][a];
				if (dist[a] > t && c[nxt][a] - f[nxt][a] > 0) {
					dist[a] = t;
					pv[a] = nxt;
					if (!visit[a]) {
						visit[a] = 1;
						q.push(a);
					}
				}
			}
		}
		if (pv[sk] == -1) break;
		for (int i = sk; i != sc; i = pv[i]) {
			ct += cost[pv[i]][i];
			f[pv[i]][i]++;
			f[i][pv[i]]--;
		}
		fw++;
	}
	cout << fw << "\n" << -ct;
}