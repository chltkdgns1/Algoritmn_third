#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
char map[51][51];
int check[51][51], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
bool visit[51][51];
vector<pair<int, int>> v[10];
int n, m;
void solve(int x, int y, int k) {
	queue <pair<int, int>> q;
	q.push({ x,y });
	vector<pair<int, int>> e;
	e.push_back({ x,y });
	visit[y][x] = 1;
	int u = 0;
	while (!q.empty()) {
		int nx = q.front().first, ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mx = nx + dx[i], my = ny + dy[i];
			if (mx < 0 || mx >= m || my < 0 || my >= n || check[my][mx] == -1) {
				u = -1;
				continue;
			}
			if (map[my][mx] - '0' > k || visit[my][mx]) continue;
			visit[my][mx] = 1;		
			q.push({ mx,my });
			e.push_back({ mx,my });
		}
	}
	if (u == -1) {
		for (auto a : e) {
			int x = a.first, y = a.second;
			if (map[y][x] - '0' == k) check[y][x] = u;
		}
	}
}
int getMin(int x, int y,int k) {
	if (check[y][x] == -1) return map[y][x] - '0';
	if (check[y][x]) return 10;
	check[y][x] = k;
	int t = 10;
	for (int i = 0; i < 4; i++) {
		t = min(t, getMin(x + dx[i], y + dy[i],k));
	}
	return t;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
			int t = map[i][k] - '0';
			if (!t) check[i][k] = -1;
			v[t].push_back({ k,i });
		}
	}
	for (int i = 1; i <= 9; i++) {
		memset(visit, 0, sizeof(visit));
		for (auto a : v[i]) {
			int x = a.first, y = a.second;
			if (!visit[y][x]) solve(x, y, i);
		}
	}
	int cnt = 1, ans = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (!check[i][k]) {
				int t = getMin(k, i, cnt);
				for (int z = 0; z < n; z++) {
					for (int q = 0; q < m; q++) {
						if (check[z][q] == cnt) 
							ans += t - (map[z][q] - '0');
					}
				}
				cnt++;
			}
		}
	}
	cout << ans << "\n";
}