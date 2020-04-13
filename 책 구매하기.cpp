#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
#define SZ 305
int n, m;
int cost[SZ][SZ], cap[SZ][SZ], f[SZ][SZ], d[SZ];
vector <int> v[SZ];

int getMcmf(int s, int e) {
	int ans = 0;
	while (1) {
		vector <int> visit(SZ, 0), dist(SZ, 1e9);
		queue <int> q; q.push(s);
		dist[s] = 0; visit[s] = 1;
		memset(d, -1, sizeof(d));

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			visit[x] = 0;
			for (auto a : v[x]) {
				if (cap[x][a] - f[x][a] > 0 && dist[a] > dist[x] + cost[x][a]) {
					dist[a] = dist[x] + cost[x][a]; d[a] = x;
					if (!visit[a]) visit[a] = 1, q.push(a);
				}
			}
		}

		if (d[e] == -1) break;

		int flow = 1e9;
		for (int i = e; i != s; i = d[i]) {
			flow = min(flow, cap[d[i]][i] - f[d[i]][i]);
		}

		for (int i = e; i != s; i = d[i]) {
			ans += flow * cost[d[i]][i];
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector <int> a(SZ), b(SZ);
	int sc = 301, sink = 302;
	// 家胶 n + m + 1 教农甫 n + m + 2; 

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v[i].push_back(sink), v[sink].push_back(i);// 教农客 楷搬
		for (int k = 1; k <= m; k++) {
			int t = 200 + k;
			v[i].push_back(t); v[t].push_back(i);
			cap[t][i] = a[i];
		}
		cap[i][sink] = a[i];
	}
	for (int i = 101; i <= m + 100; i++) {
		cin >> b[i];
		int t = i + 100;
		v[i].push_back(t), v[t].push_back(i);
		v[i].push_back(sc), v[sc].push_back(i);
		cap[i][t] = cap[sc][i] = b[i];
	}

	for (int i = 1; i <= m; i++) {
		for (int k = 1; k <= n; k++) {
			int t = 200 + i;
			cin >> cost[t][k];
			cost[k][t] = -cost[t][k];
		}
	}

	cout << getMcmf(sc, sink) << "\n";
	system("pause");
}