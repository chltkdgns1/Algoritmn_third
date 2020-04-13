#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include<vector>
using namespace std;
int map[101];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int a, b; cin >> a >> b;
		map[a] = b;
	}
	vector<int>dp(101);
	for (int i = 1; i <= 100; i++) dp[i] = 1e9;
	queue <int> q;
	q.push(1);
	dp[1] = 0;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (map[t]) {
			int s = map[t];
			if (dp[s] > dp[t]) {
				dp[s] = dp[t];
				q.push(map[t]);
			}
			continue;
		}
		for (int i = 1; i <= 6; i++) {
			int a = t + i;
			if (a <= 100) {
				if (map[a]) {
					if (dp[map[a]] > dp[t] + 1) {
						dp[map[a]] = dp[t] + 1;
						q.push(map[a]);
					}
				}
				else if (dp[a] > dp[t] + 1) {
					dp[a] = dp[t] + 1;
					q.push(a);
				}
			}
			else break;
		}
	}
	cout << dp[100] << "\n";
}
