#include <iostream>
#include <queue>
using namespace std;
bool map[1001][1001];
bool visit[1001][1001];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int n, m;
class Data {
public:
	int x, y, dist;
};
bool check(int x, int y, int w, int h) {
	if (x >= 1 && x <= m && y >= 1 && y <= n) {
		if (x + w - 1 <= m && y + h - 1 <= n) return 1;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) cin >> map[i][k];
	}
	int h, w, sr, sc, fr, fc; cin >> h >> w >> sr >> sc >> fr >> fc;
	queue<Data> q;
	q.push({ sc,sr,0 });
	visit[sr][sc] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().dist;
		q.pop();
		if (x == fc && y == fr) {
			cout << d << "\n";
			return  0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check(nx, ny, w, h) && !visit[ny][nx]) {
				bool ch = 0;
				int my = y + h, mx = x + w;
				if (!i) {
					for (int k = nx; k < nx + w; k++) {
						if (map[my][k]) { ch = 1; break; }
					}
				}
				else if (i == 1) {
					for (int k = nx; k < nx + w; k++) {
						if (map[ny][k]) { ch = 1; break; }
					}
				}
				else if (i == 2) {
					for (int k = ny; k < ny + h; k++) {
						if (map[k][mx]) { ch = 1; break; }
					}
				}
				else {
					for (int k = ny; k < ny + h; k++) {
						if (map[k][nx]) { ch = 1; break; }
					}
				}
				if (!ch) visit[ny][nx] = 1, q.push({ nx,ny,d + 1 });
			}
		}
	}
	cout << -1 << "\n";
}