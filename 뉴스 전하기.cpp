#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visit[51];
vector<int> v[51];
int solve(int s,int p) {
	if (v[s].size() == 1 && s != 1) return 0;
	visit[s] = 1;
	vector<int> e;
	for (auto a : v[s]) {
		if (a == p)continue;
		if (!visit[a]) e.push_back(solve(a, s));
	}
	sort(e.rbegin(), e.rend());
	int mx = 0;
	for (int i = 0; i < e.size(); i++) mx = max(mx, e[i] + i + 1);
	return mx;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a == -1) continue;
		v[i].push_back(++a);
		v[a].push_back(i);
	}
	cout << solve(1, -1) << "\n";
}