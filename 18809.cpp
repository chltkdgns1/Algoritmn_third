#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int map[51][51], sel[11], time[51][51], color[51][51];
bool fch[51][51];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> v(11);
class Data {
public:
	int x, y, col;
};
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, g, r; cin >> n >> m >> g >> r;
	int order = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			if (map[i][k] == 2) v[++order] = { k,i };
		}
	}
	int st = order - g - r;
	for (int i = st + 1; i <= st + g; i++) sel[i] = 1;
	for (int i = st + g + 1; i <= st + g + r; i++) sel[i] = 2;
	int ans = 0;
	do {
		int f = 0;
		memset(time, 0, sizeof(time)), memset(color, 0, sizeof(color));
		memset(fch, 0, sizeof(fch));
		queue<pair<int, Data>> q;
		for (int i = 1; i <= order; i++) {
			int x = v[i].first, y = v[i].second; 
			if (sel[i] == 1) q.push({ 1,{x,y,1} }), color[y][x] = time[y][x] = 1;
			else if (sel[i] == 2) q.push({ 1,{x,y,2} }), time[y][x] = 1, color[y][x] = 2;
		}
		while (!q.empty()) {
			int tm = q.front().first;
			Data d = q.front().second;
			int x = d.x, y = d.y, col = d.col;
			q.pop();
			if (fch[y][x]) continue;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n || !map[ny][nx]) continue;

				if (time[ny][nx]) {
					if (!fch[ny][nx] && time[ny][nx] == tm + 1
						&& color[ny][nx] != col) f++, fch[ny][nx] = 1;
					continue;
				}
				time[ny][nx] = tm + 1, color[ny][nx] = col;
				q.push({ tm + 1,{nx,ny,col} });		
			}
		}
		ans = max(ans, f);
	} while (next_permutation(sel + 1, sel + order + 1));
	cout << ans << "\n";
}