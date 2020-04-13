#include <iostream>
#include <queue>
using namespace std;
char map[51][51];
int dist[51][51];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
class Data {
public:
	int x, y, b;
};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> map[i];
	queue <Data> q;
	for (int i = 0; i < n; i++) for (int k = 0; k < n; k++) dist[i][k] = 1e9;
	dist[0][0] = 0;
	q.push({ 0,0,0 });
	while (!q.empty()) {
		Data ds = q.front(); q.pop();
		int x = ds.x, y = ds.y, b = ds.b;
		if (dist[y][x] < b) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (map[ny][nx] == '0') {
				if (dist[ny][nx] > b + 1) {
					dist[ny][nx] = b + 1;
					q.push({ nx,ny,b + 1 });
				}
				continue;
			}
			if (dist[ny][nx] > b) {
				dist[ny][nx] = b;
				q.push({ nx,ny,b });
			}
		}
	}
	cout << dist[n - 1][n - 1] << "\n";
}