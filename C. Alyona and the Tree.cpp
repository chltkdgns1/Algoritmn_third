#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll arr[100001], dp[100001], sz[100001];
vector <pair<int, int>> v[100001];

int dfs(int s, int p,int q) {
	dp[s] = q; sz[s] = 1;
	for (auto a : v[s]) {
		if (a.first == p) continue;
		if(q >= 0) sz[s] += dfs(a.first, s, q + a.second);
		else sz[s] += dfs(a.first, s, max(q, a.second));
	}
	return sz[s];
}

ll solve(int s, int p) {
	int res = 0;
	if (dp[s] > arr[s]) return sz[s];
	for (auto a : v[s]) {
		if (a.first == p) continue;	
		res += solve(a.first, s);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,a,b; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 2; i <= n; i++) {
		cin >> a >> b;
		v[a].push_back({ i,b });
	}

	dfs(1, -1, 0);
	cout << solve(1, -1) << "\n";
}