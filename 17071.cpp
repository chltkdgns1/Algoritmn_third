#include <iostream>
#include <queue>
using namespace std;

int dist[500001][2];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	if (a == b) cout << 0, exit(0);
	queue <pair<int, pair<int,int>>> q;
	q.push({ 0,{a,1} }), q.push({ 0,{b,2} });
	int ans = 1e9, cnt = 1;
	while(!q.empty()){
		int cnt = q.front().first;
		int x = q.front().second.first;
		int col = q.front().second.second; q.pop();
		++cnt; 
		if (col == 1) {
			int n = 0;
			if (cnt & 1) n = 1;
			if (x + 1 <= 500000 && !dist[x + 1][n])
				dist[x + 1][n] = cnt, q.push({ cnt,{x + 1,1} });
			if (x - 1 >= 0 && !dist[x - 1][n])
				dist[x - 1][n] = cnt, q.push({ cnt,{x - 1,1} });
			if (x * 2 <= 500000 && !dist[2 * x][n])
				dist[2 * x][n] = cnt, q.push({ cnt,{2 * x,1} });
		}
		else {
			if (x + cnt <= 500000) {
				int t = dist[x + cnt][cnt & 1];
				if (t && t <= cnt) {
					ans = min(ans, cnt);
					break;
				}
				q.push({ cnt,{x + cnt,2}});
				cnt++;
			}
			cnt--;
			if (!cnt) break;
		}
	}
	if (ans == 1e9) ans = -1;
	cout << ans << "\n";
}