#include <iostream>
#include <queue>
using namespace std;

queue <pair<int, int>> q[1001];
int map[201][201];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> map[i][k];
			q[map[i][k]].push({ k,i });
		}
	}
	int s, x, y; cin >> s >> x >> y;
	while (s--) {
		for (int i = 1; i <= m; i++) {
			int t = q[i].size();
			while (t--) {
				int nx = q[i].front().first;
				int ny = q[i].front().second;
				q[i].pop();
				for (int k = 0; k < 4; k++) {
					int mx = nx + dx[k];
					int my = ny + dy[k];
					if (mx >= 0 && mx < n && my >= 0 && my < n) {
						if (!map[my][mx]) {
							map[my][mx] = i;
							q[i].push({ mx,my });
						}
					}
				}
			}
		}
	}

	cout << map[x - 1][y - 1] << "\n";
}