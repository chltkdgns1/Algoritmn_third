#include <iostream>
using namespace std;

int v[1001][1001];
int gr[1001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;

	while(1){
		int a, b; cin >> a >> b;
		if (a == -1 && b == -1) break;
		v[a][b] = v[b][a] = 1;
	}
	gr[1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			if (i == k) continue;

			if (!v[i][k]) {
				if (gr[i] == gr[k] && gr[i]) return cout << -1, 0;
				else if (!gr[i] && gr[k]) gr[i] = 3 - gr[k];
				else if (!gr[k] && gr[i]) gr[k] = 3 - gr[i];
			}
		}
	}
	cout << 1 << "\n";
	for (int i = 1; i <= n; i++) if (gr[i] == 1) cout << i << " ";
	cout << "-1\n";
	for (int i = 1; i <= n; i++) if (gr[i] != 1) cout << i << " ";
	cout << "-1\n";
}