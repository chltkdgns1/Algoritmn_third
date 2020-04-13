#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define xx first
#define yy second
char map[51][51];
int visit[51][51][4], dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
class Data {
public:
	int x, y, dir;
};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int x = -1, y, ex, ey;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> map[i][k];
			if (map[i][k] == '#') {
				if (x == -1) x = k, y = i;
				else ex = k, ey = i;
			}
			for (int z = 0; z < 4; z++) visit[i][k][z] = 1e9;
		}
	}
	queue < pair<int, Data>> q;
	int ans = 1e9;
	for (int i = 0; i < 4; i++) q.push({ 0,{x,y,i} });
	while (!q.empty()) {
		int mir = q.front().xx;
		int x = q.front().yy.x, y = q.front().yy.y;
		int dir = q.front().yy.dir;
		q.pop();
		if (x == ex && y == ey) {
			ans = min(ans, mir);
			continue;
		}
		if (visit[y][x][dir] < mir) continue;
		int nx, ny;	
		for (int i = -1; i <= 1; i++) {
			int dr = dir + i;
			if (dr < 0) dr = 3; else dr %= 4;
			nx = x + dx[dr], ny = y + dy[dr];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n ||
				map[ny][nx] == '*') continue;
			if (!i) {
				if (visit[ny][nx][dr] > mir) {
					visit[ny][nx][dr] = mir; q.push({ mir,{nx,ny,dr} });
				}
			}
			else if (map[y][x] == '!') {
				if (visit[ny][nx][dr] > mir + 1) {
					visit[ny][nx][dr] = mir + 1;
					q.push({ mir + 1,{nx,ny,dr} });
				}
			}
		}	
	}
	cout << ans << "\n";
}