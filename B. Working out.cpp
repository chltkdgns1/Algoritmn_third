#include <iostream>
#include <algorithm>
using namespace std;

int adp[1002][1002][2], a[1002][1002], bdp[1002][1002][2];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++) for (int k = 1; k <= m; k++) {
		cin >> a[i][k];
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			int x = n + 1 - i, y = m + 1 - k;
			adp[i][k][0] = max(adp[i - 1][k][0], adp[i][k - 1][0]) + a[i][k];
			adp[x][k][1] = max(adp[x + 1][k][1], adp[x][k - 1][1]) + a[x][k];
			bdp[x][y][0] = max(bdp[x + 1][y][0], bdp[x][y + 1][0]) + a[x][y];
			bdp[i][y][1] = max(bdp[i - 1][y][1], bdp[i][y + 1][1]) + a[i][y];
		}
	}

	int res = 0;
	for (int i = 2; i < n; i++) {
		for (int k = 2; k < m; k++) {
			res = max(res,
				max(adp[i - 1][k][0] + bdp[i + 1][k][0] +
				adp[i][k - 1][1] + bdp[i][k + 1][1],
				adp[i][k - 1][0] + bdp[i][k + 1][0]+
				adp[i + 1][k][1] + bdp[i - 1][k][1]));
		}
	}
	cout << res << "\n";
}