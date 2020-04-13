#include <iostream>
#include <algorithm>
using namespace std;
int map[21], n;
int solve(int idx) {
	int res = 1e9;
	if (idx == n) {
		res = 0;
		for (int k = 0; k < n; k++) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (map[i] & (1 << (n - k - 1))) cnt++;
			}
			res += min(n - cnt, cnt);
		}
		return res;
	}

	map[idx] = ~map[idx];
	res = min(res,solve(idx + 1));
	map[idx] = ~map[idx];
	res = min(res,solve(idx + 1));
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	 cin >> n;
	for (int i = 0; i < n; i++) for (int k = 0; k < n; k++) {
		char a; cin >> a;
		if (a == 'T') map[i] |= (1 << (n - k - 1));
	}
	cout << solve(0);
}