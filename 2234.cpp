#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[51][51], visit[51][51], rsize[2501];
int dx[4] = { -1,0,1,0 }, dy[4] = {0,-1,0,1 };
int n, m;
vector<int>v[2501];
bool check(int x, int y) {
	return x < 0 || x >= m || y < 0 || y >= n;
}
int solve(int x, int y,int col) {
	visit[y][x] = col;
	int size = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (check(nx,ny) || (map[y][x] & (1<<i)) || visit[ny][nx]) continue;
		size += solve(nx, ny, col);
	}
	return size;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) cin>> map[i][k];
	}
	int col = 0, mxr = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (!visit[i][k]) rsize[++col] = solve(k, i, col), mxr = max(mxr, rsize[col]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			for (int z = 0; z < 4; z++) {
				int x = k + dx[z], y = i + dy[z];
				if (check(x, y)) continue;
				if (visit[i][k] != visit[y][x]) {
					v[visit[i][k]].push_back(visit[y][x]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= col; i++) {
		for (auto a : v[i]) {
			ans = max(ans, rsize[i] + rsize[a]);
		}
	}
	cout << col << "\n" << mxr << "\n" << ans;
}