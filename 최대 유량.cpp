#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
vector <int> v[201];
bool visit[201];
int d[201];
bool solve(int s) {
	for (auto a : v[s]) {
		if (!visit[a]) {
			visit[a] = 1;
			if (!d[a] || solve(d[a])) {
				d[a] = s;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m,a,b; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int k = 0; k < a; k++) {
			cin >> b;
			v[i].push_back(b);
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if (solve(i)) res++;
	}
	cout << res << "\n";
}