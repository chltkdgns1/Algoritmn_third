#include <iostream>
#include <vector>
using namespace std;
int n, m;
int main() {
	cin >> n >> m;
	int a[n][m], ans[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j], a[i][j]--;
	int ret = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)ans[j] = j + n;
		for (int j = 0; j < n; j++)
			if (a[j][i] % m == i && a[j][i] < m*n)
				ans[(j - (a[j][i] / m) + n) % n]--;
		int rett = INT_MAX;
		for (int j = 0; j < n; j++)rett = min(rett, ans[j]);
		ret += rett;
	}
	cout << ret;
}