#include <iostream>
#include <vector>
using namespace std;

#define F(i,n) for(int i=1;i<=n;i++)

int n;
int p[1001][1001];
int g[1001];

int main() {
	cin.sync_with_stdio(0);
	cin >> n;

	while (1) {
		int a, b; cin >> a >> b;
		if (!~a)break;
		p[a][b] = p[b][a] = 1;
	}

	g[1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int h = 1; h <= n; h++) {
			if (i == h)continue;

			if (!p[i][h]) {
				if (g[i] == g[h] && g[i])return cout << -1, 0;
				if (!g[h] && g[i])g[h] = 3 - g[i];
				if (!g[i] && g[h])g[i] = 3 - g[h];
			}
		}
	}

	for (int i = 1; i <= n; i++) if (!g[i])g[i] = 1;

	vector<int>A, B;
	for (int i = 1; i <= n; i++) {
		if (g[i] & 1)A.push_back(i);
		else B.push_back(i);
	}

	cout << "1\n";
	for (int i : A)cout << i << ' '; cout << "-1\n";
	for (int i : B)cout << i << ' '; cout << "-1\n";
}