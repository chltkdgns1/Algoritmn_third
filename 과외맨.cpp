#include <iostream>
#include <queue>
using namespace std;
int map[501][1001], numbering[501][1001];
int dist[250001], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
vector<int> v[250001];
void traceing(int s) {
	if (s == 1) {
		cout << s << " ";
		return;
	}
	for (auto a : v[s]) {
		if (dist[a] + 1 == dist[s]) {
			traceing(a);
			cout << s << " ";
			break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int t = i % 2;
		for (int k = 0; k < n - t; k++) {
			cin >> map[i][2*k + t] >> map[i][2*k + 1 + t];
			numbering[i][2 * k + t] = numbering[i][2 * k + t + 1] = cnt;
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		int t = i % 2;
		for (int k = 0; k < n - t; k++) {
			for (int z = 0; z < 2; z++) {
				int u = k * 2 + z + t;
				for (int q = 0; q < 4; q++) {
					int x = u + dx[q];
					int y = i + dy[q];
					if (x < 0 || x >= 2 * n || y < 0 || y >= n) continue;
					if (!map[y][x]) continue;

					if (map[i][u] == map[y][x] && 
						numbering[i][u] != numbering[y][x]) {
						v[numbering[i][u]].push_back(numbering[y][x]);
					}
				}
			}
		}
	}
	queue <int> q;
	q.push(1);
	for (int i = 1; i < cnt; i++) dist[i] = 1e9;
	dist[1] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto a : v[x]) {
			if (dist[a] > dist[x] + 1) {
				dist[a] = dist[x] + 1;
				q.push(a);
			}
		}
	}
	int idx;
	for (int i = cnt - 1; i >= 1; i--) if (dist[i] != 1e9) {
		cout << dist[i]<<"\n"; idx = i; break;
	}
	traceing(idx);
}