#include <iostream>
#include <queue>
using namespace std;
#define a first
#define b second
char map[101][101];
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int visit[101][101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> m >> n;
	int x = -1, y, ex, ey;
	for (int i = 0; i < n; i++) cin >> map[i];
	for (int i = 0; i < n; i++) for (int k = 0; k < m; k++) if (map[i][k] == 'C') {
		if (x == -1) x = k, y = i;
		else ex = k, ey = i;
	}
	queue <pair<int, pair<int,pair<int,int>>>> q;
	for (int i = 0; i < 4; i++) q.push({ 0,{x,{y,i}} });
	for (int i = 0; i < n; i++) for (int k = 0; k < m; k++) visit[i][k] = 1e9;
	visit[y][x] = 0;
	int res = 1e9;
	while (!q.empty()) {
		int mircnt = q.front().first;
		int x = q.front().b.a, y = q.front().b.b.a, dir = q.front().b.b.b;
		q.pop();
		if (x == ex && y == ey) {
			res = min(res, mircnt);
			continue;
		}
		for (int i = -1; i <= 1; i++) {
			int k = dir + i;
			if (k < 0) k = 3;
			else k %= 4;
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n || map[ny][nx] == '*') continue;

			int mir = mircnt + (!i ? 0 : 1);
			if (visit[ny][nx] >= mir) {
				visit[ny][nx] = mir; q.push({ mir,{nx,{ny,k}} });
			}
		}
	}
	cout << res << "\n";
}