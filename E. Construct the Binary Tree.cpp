#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int depth[5001], p[5001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		vector <int> gp[5001];
		memset(depth, 0, sizeof(depth)), memset(p, 0, sizeof(p));
		int n, d; cin >> n >> d;
		int dpth = 0, sum = 0;
		for (int i = 2, k = 2; i <= n; i += k, k *= 2) {
			dpth++;
			for (int z = i; z < min(i + k, n + 1); z++) {
				p[z] = z / 2; depth[z] = dpth;
				gp[dpth].push_back(z); sum += dpth;
			}
		}
		if (sum > d || n * (n - 1) / 2 < d) {
			cout << "NO\n"; continue;
		}
		
		int cnt = d - sum, node = n;
		while (cnt--) {
			while (gp[depth[node]].size() == 1) node--;
			gp[depth[node]].pop_back();
			depth[node]++; gp[depth[node]].push_back(node);
			int size = gp[depth[node]].size();
			p[node] = gp[depth[node] - 1][(size - 1) / 2];
		}

		cout << "YES\n";
		for (int i = 2; i <= n; i++) cout << p[i] << " ";
		cout << "\n";
	}
}