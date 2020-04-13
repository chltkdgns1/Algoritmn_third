#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define xx first
#define yy second
char map[1001][1001];
int visit[1001][1001];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 }, ans[10];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector <pair<int, int>> v[10];
	int n, m, p; cin >> n >> m >> p;
	vector<int>e(p + 1);
	for (int i = 1; i <= p; i++) cin >> e[i];
	int get = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k] != '.' && map[i][k] != '#') {
				get++;
				int t = map[i][k] - 48;
				v[t].push_back({ k,i });
				visit[i][k] = t;
			}
			else if (map[i][k] == '#') get++;
		}
	}
	int cnt = 0;
	while (cnt < n*m - get) {
		int ck = 0;
		for (int i = 1; i <= p; i++) {
			queue <pair<int, pair<int, int>>> q;
			for (auto a : v[i]) q.push({ e[i],a });
			v[i].clear();
			while (!q.empty()) {
				int c = q.front().xx;
				int x = q.front().yy.xx, y = q.front().yy.yy;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
						visit[ny][nx]) continue;

					if (map[ny][nx] == '.') {
						visit[ny][nx] = i;
						cnt++; ck++;
						if (c != 1) q.push({ c - 1,{nx,ny} });
						else v[i].push_back({ nx,ny });
					}
				}
			}
		}
		if (!ck) break;
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) ans[visit[i][k]]++;
	}
	for (int i = 1; i <= p; i++) cout << ans[i] << " ";
}