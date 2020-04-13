#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define SIZE 1006
const int inf = 1e9;
using namespace std;
class flow {
public:
	int to, cost, cap, f;
};
vector <flow> v[SIZE];
void addEdge(int s, int e, int cost, int cap) {
	v[s].push_back({ e,cost,cap,int(v[e].size()) });
	v[e].push_back({ s,-cost,0,int(v[s].size()) - 1 });
}
int solve(int s, int e) {
	int flow = 0, cost = 0;
	vector <int> bac(SIZE, -1), fr(SIZE, -1);
	while (1) {
		vector <int> dist(SIZE, inf), visit(SIZE, 0);
		queue <int> q;
		q.push(s);
		dist[s] = 0;
		visit[s] = 1;
		while (!q.empty()) {
			int n = q.front(); q.pop();
			visit[n] = 0;
			for(int i=0;i<v[n].size();i++){
				int cp = v[n][i].cap, nxt = v[n][i].to, cst = v[n][i].cost;
				if (cp && dist[nxt] > dist[n] + cst) {
					dist[nxt] = cst + dist[n];
					bac[nxt] = n; fr[nxt] = i;
					if (!visit[nxt]) visit[nxt] = 1, q.push(nxt);
				}
			}
		}
		if (dist[e] != inf) {
			int min_flow = inf;
			for (int i = e; i != s; i = bac[i]) {
				min_flow = min(min_flow, v[bac[i]][fr[i]].cap);
			}

			for (int i = e; i != s; i = bac[i]) {
				int x = bac[i], y = fr[i];
				v[x][y].cap -= min_flow;
				v[i][v[x][y].f].cap += min_flow;
				cost += v[x][y].cost*min_flow;
			}
			flow += min_flow;
		}
		else return cost;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, b, x, y, z;
	while (cin >> n >> a >> b) {
		if (!n && !a && !b) break;
		addEdge(n + 1, n + 2, 0, a);
		addEdge(n + 1, n + 3, 0, b);
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			addEdge(n + 2, i, y, inf);
			addEdge(n + 3, i, z, inf);
			addEdge(i, n + 4, 0, x);
		}
		cout << solve(n + 1, n + 4) << "\n";

		for (int i = 0; i < SIZE; i++) v[i].clear();
	}
}