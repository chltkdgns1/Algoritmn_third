#include <iostream>
#include <algorithm>
using namespace std;

int dp[51][51][3];
char map[51][51];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;

	for (int i = 0; i <= n; i++) 
		for (int k = 0; k <= m; k++) {
			map[i][k] = '.';
			for (int z = 0; z < 3; z++) dp[i][k][z] = 1e9;
		}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			cin >> map[i][k];
			
			if (map[i][k] != '.') {
				if (map[i - 1][k] == '.' && map[i][k - 1] == '.') {

				}
				else if (map[i][k - 1] != '.' && map[i][k - 1] == '.') {

				}
				else {

				}
			}
			else {
				int x = 1e9, y = 1e9;
				for (int z = 0; z < 3; z++) {
					x = min(x, dp[i - 1][k][z]);
					y = min(y, dp[i][k - 1][z]);
				}
				dp[i][k][0] = min(int(1e9), x + y);
			}
		}
	}
}