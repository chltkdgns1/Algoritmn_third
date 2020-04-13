#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
vector<pair<int, int>> v[2011];
int dist[2011],cur[2011];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int s, e, n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	cin >> s >> e;
	for (int i = 1; i <= n; i++) dist[i] = 1e9;
	priority_queue <pair<int, int>> q;
	q.push({ 0,s });
	dist[s] = 0;
	while (!q.empty()) {
		int d = -q.top().first, next = q.top().second;
		q.pop();
		for (auto a : v[next]) {
			if (dist[a.first] > dist[next] + a.second) {
				cur[a.first] = next;
				dist[a.first] = dist[next] + a.second;
				q.push({ -dist[a.first],a.first });
			}
		}
	}
	cout << dist[e] << "\n";
	vector<int>ans;
	while (e) {
		ans.push_back(e);
		e = cur[e];
	}
	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
	return 0;
}