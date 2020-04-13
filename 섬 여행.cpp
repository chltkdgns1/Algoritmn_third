#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using  namespace std;

int a[101];
int dist[101][101];
map <pair<int, int>, vector<int>> mp;
map <pair<int, int>, int> mq;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) dist[i][k] = (i == k ? 0 : 1e9);
	}

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		dist[a][b] = 1, dist[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			for (int z = 1; z <= n; z++) {
				if (dist[i][z] > dist[i][k] + dist[k][z]) {
					dist[i][z] = dist[i][k] + dist[k][z];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			if (dist[i][k] == 1e9) continue;
			mp[{i, dist[i][k]}].push_back(k);
			if (!mq.count({ i, dist[i][k] })) mq[{i, dist[i][k]}] = 1e9;
			mq[{i, dist[i][k]}] = min(mq[{i, dist[i][k]}], a[k]);
		}
	}
	int z; cin >> z;
	while (z--) {
		int x, y; cin >> x >> y;
		int ans = 1e9;
		for (int i = 1; i <= y; i++) {
			for (auto a : mp[{x, i}]) {
				int t = mq[{a, y - i}];
				if(t) ans = min(ans,t);
			}
		}
		if (ans == 1e9) ans = -1;
		cout << ans << "\n";
	}
}