#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001]; bool visit[1001][1001][2];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
class Data {
public:
	int x, y, a, b;
};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, x, y, ex, ey; cin >> n >> m >> y >> x >> ey >> ex;
	for (int i = 1; i <= n; i++) for (int k = 1; k <= m; k++) cin >> map[i][k];
	queue<Data> q;
	q.push({ x,y,0,0 });
	visit[y][x][0] = 1;
	while (!q.empty()) {
		Data d = q.front();
		int x = d.x, y = d.y, dist = d.a, c = d.b;
		q.pop();
		if (x == ex && y == ey) {
			cout << dist;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
			if (map[ny][nx]) {
				if (c || visit[ny][nx][c + 1]) continue;
				visit[ny][nx][c + 1] = 1;
				q.push({ nx,ny,dist + 1,1 });
			}
			else {
				if (visit[ny][nx][c]) continue;
				visit[ny][nx][c] = 1;
				q.push({ nx,ny,dist + 1,c });
			}
		}
	}
	cout << -1;
}