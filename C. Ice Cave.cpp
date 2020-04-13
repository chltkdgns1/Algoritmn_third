#include <iostream>
#include <algorithm>
using namespace std;

bool visit[501][501];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
char map[501][501];
int n, m, q, r, a, b;

bool check(int x, int y) {
	return x < 0 || y < 0 || x >= m || y >= n;
}

void solve(int x, int y) {
	if (check(x, y) || visit[y][x]) return;
	if (map[y][x] == 'X') { visit[y][x] = 1; return; }
	if (x == b && y == a) map[y][x] = 'X';
	visit[y][x] = 1;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		solve(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) cin >> map[i][k];
	}
	cin >> a >> b >> q >> r;
	a--, b--, q--, r--;
	map[a][b] = '.';
	solve(b, a);
	if (!visit[q][r]) cout << "NO\n";
	else {
		int res = 0;
		for (int i = 0; i < 4; i++) {
			int nx = r + dx[i], ny = q + dy[i];
			if (nx == b && ny == a) res++;
			else if (!check(nx, ny) && map[ny][nx] == '.' && visit[ny][nx]) res++;
		}
		if (map[q][r] == 'X') {
			if (res) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			if (res >= 2) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}