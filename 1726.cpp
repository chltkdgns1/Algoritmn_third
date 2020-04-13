#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int map[101][101];
int dx[5] = { 0, 1, -1,0,0 }, dy[5] = { 0,0,0,1,-1 };
int dp[101][101][5];
class Data {
public:
	int x, y, dir, dist;
};
int cal(int a, int b) {
	if (a == b) return 0;
	if ((a <= 2 && b <= 2) || (a > 2 && b > 2)) return 2;
	return 1;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			cin >> map[i][k];
		}
	}
	for (int i = 1; i <= n; i++) for (int k = 1; k <= m; k++) for (int z = 1; z <= 4; z++)
		dp[i][k][z] = 1e9;
	int a, b, s, e, c, z; cin >> a >> b >> c >> s >> e >> z;
	queue <Data> q;
	dp[a][b][c] = 0;
	q.push({ b,a,c,0 });
	int ans = 1e9;
	while (!q.empty()) {
		Data d = q.front();
		q.pop();
		int x = d.x, y = d.y, dir = d.dir, dist = d.dist;
		if (dp[y][x][dir] < dist) continue;
 		for (int i = 1; i <= 4; i++) {
			for (int k = 0; k <= 3; k++) {
				int nx = x + dx[i]*k;
				int ny = y + dy[i]*k;
				if (nx < 1 || nx > m || ny < 1 || ny > n || map[ny][nx] == 1)
					break;
				int td = dist + cal(dir, i) + (!k ? 0 : 1);
				if (dp[ny][nx][i] > td) {
					dp[ny][nx][i] = td;
					q.push({ nx,ny,i,td });
				}
			}
		}
	}
	cout << dp[s][e][z] << "\n";
}