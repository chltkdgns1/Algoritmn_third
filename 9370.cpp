#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
int d[2001], g, h;
bool check;
vector <pair<int, int>> v[2001];
void dikstra(int s, int n) {
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[s] = 0;
	priority_queue <pair<int, int>> q;
	q.push({ 0,s });
	while (!q.empty()) {
		int cost = -q.top().first;
		int x = q.top().second;
		q.pop();
		if (d[x] < cost) continue;
		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i].first;
			int dist = v[x][i].second;
			if (d[next] > cost + dist) {
				d[next] = cost + dist;
				q.push({ -d[next],next });
			}
		}
	}
}
void dfs(int s) {
	if (check) return;
	for (int i = 0; i < v[s].size(); i++) {
		int y = v[s][i].first;
		int dis = v[s][i].second;
		if (d[s] == d[y] + dis) {
			if ((s == g && y == h) || (s == h && y == g)) {
				check = 1;
				break;
			}
			dfs(y);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, m, t; cin >> n >> m >> t;
		int s; cin >> s >> g >> h;
		for (int i = 0; i < m; i++) {
			int a, b, d; cin >> a >> b >> d;
			v[a].push_back({ b,d });
			v[b].push_back({ a,d });
		}
		dikstra(s, n);
		vector <int> e;
		for (int i = 0; i < t; i++) {
			check = 0;
			int a; cin >> a;
			dfs(a);
			if (check) e.push_back(a);
		}
		sort(e.begin(), e.end());
		for (int i = 0; i < e.size(); i++) cout << e[i] << " ";
		cout << "\n";
		for (int i = 1; i <= n; i++) v[i].clear();
	}
}