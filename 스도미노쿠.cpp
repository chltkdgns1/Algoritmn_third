#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
int map[9][9];
bool check[10][10];
int dx[4] = { 0,0,1,-1}, dy[4] = { 1,-1,0,0};
int ans;
vector<pair<int, int>>v;
void print() {
	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) cout << map[i][k];
		cout << "\n";
	}
}
bool backTracking(int x, int y, int n) {
	for (int i = 0; i < 9; i++) {
		if (map[i][x] == n || map[y][i] == n) return 0;
	}
	int s = x / 3 * 3,e = s + 3;
	int l = y / 3 * 3, r = l + 3;
	for (int i = l; i < r; i++) {
		for (int k = s; k < e; k++) {
			if (map[i][k] == n) return 0;
		}
	}
	return 1;
}
void solve(int idx) {
	if (idx == v.size()) {
		print(); ans = 1;
		return;
	}
	int x = v[idx].first, y = v[idx].second;
	if (map[y][x]) {
		solve(idx + 1);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 9 && ny >= 0 && ny < 9) {
			if (!map[ny][nx]) {
				for (int i = 1; i < 9; i++) {
					for (int k = i + 1; k <= 9; k++) {
						if (check[i][k] && check[k][i]) continue;
						if (backTracking(x, y, i) && backTracking(nx, ny, k)) {
							map[y][x] = i, map[ny][nx] = k;
							check[i][k] = check[k][i] = 1;
							solve(idx + 1);
							if (ans) return;
							check[i][k] = check[k][i] = 0;
							map[y][x] = 0, map[ny][nx] = 0;
						}
						if (backTracking(x, y, k) && backTracking(nx, ny, i)) {
							map[y][x] = k, map[ny][nx] = i;
							check[i][k] = check[k][i] = 1;
							solve(idx + 1);
							if (ans) return;
							check[i][k] = check[k][i] = 0;
							map[y][x] = 0, map[ny][nx] = 0;
						}
					}
				}
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int cnt = 1;
	while (1) {
		int n; cin >> n;
		if (!n) break;
		v.clear(); 
		memset(check, 0, sizeof(check));
		memset(map, 0, sizeof(map));
		ans = 0;
		for (int i = 0; i < n; i++) {
			int a, b; string x, y;
			cin >> a >> x >> b >> y;
			check[a][b]= check[b][a] = 1;
			map[x[0] - 'A'][x[1] - '0' - 1] = a;
			map[y[0] - 'A'][y[1] - '0' - 1] = b;
		}
		for (int i = 1; i <= 9; i++) {
			string s; cin >> s;
			map[s[0] - 'A'][s[1] - '0' - 1] = i;
		}
		cout << "Puzzle " << cnt++ << "\n";
		for (int i = 0; i < 9; i++) {
			for (int k = 0; k < 9; k++) {
				if (!map[i][k]) v.push_back({ k,i });
			}
		}
		solve(0);
	}
}