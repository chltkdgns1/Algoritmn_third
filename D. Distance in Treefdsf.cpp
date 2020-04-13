#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector <int> v[50001];
ll dp[50001][501], res;
int n, m, a, b;
void dfs(int s, int p) {
	dp[s][0] = 1;
	for (auto a : v[s]) {
		if (a == p) continue;
		dfs(a, s);
		for (int k = 1; k <= m; k++)
			res += dp[s][k - 1] * dp[a][m - k];
		for (int k = 1; k <= m; k++)
			dp[s][k] += dp[a][k - 1];
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b), v[b].push_back(a);
	}

	dfs(1, -1);
	cout << res << "\n";
}