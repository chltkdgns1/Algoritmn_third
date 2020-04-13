#include <iostream>
using namespace std;
int a[101][101], b[101][101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n*2; i++) {
		for (int k = 0; k < m; k++) {
			if (i < n) cin >> a[i][k];
			else cin >> b[i - n][k];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) cout << a[i][k] + b[i][k] << " ";
		cout << "\n";
	}
}