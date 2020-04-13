#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
priority_queue<int> dp[1001];
vector<pair<int, int>> v[1001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	priority_queue<pair<int, int>> q;
	q.push({ 0,1 });
	dp[1].push(0);
	while (!q.empty()) {
		int node = q.top().second;
		int dist = -q.top().first;
		q.pop();
		for (auto a : v[node]) {
			if (dp[a.first].size() >= k) {
				int t = dp[a.first].top();
				if (t <= dist + a.second) continue;
				dp[a.first].pop();
			}
			dp[a.first].push(dist + a.second);
			q.push({ -(dist + a.second),a.first });
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << (dp[i].size() < k ? -1 : dp[i].top()) << "\n";
	}
}