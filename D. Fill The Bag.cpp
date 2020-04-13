#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		ll n, m; cin >> n >> m;
		ll sum = 0;
		priority_queue <int> q;
		for (int i = 0; i < m; i++) {
			int a; cin >> a;
			sum += a; q.push(a);
		}
		int cnt = 0;

		if (sum < n) cout << "-1\n";
		else {
			while (n) {
				int t = q.top(); q.pop();
				if (t <= n)  n -= t, sum -= t;
				else {
					if (sum - t < n) {
						cnt++;
						q.push(t / 2), q.push(t / 2);
					}
					else if (sum - t == n) break;
					else sum -= t;
				}
				
			}
			cout << cnt << "\n";
		}
	}
}