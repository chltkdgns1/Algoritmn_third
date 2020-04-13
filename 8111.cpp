#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
int n, ch[101],c;
bool check(int s) {
	if (!s) return 0;
	while (s) {
		int t = s % 10;
		if (1 < t)return 0;
		s /= 10;
	}
	return 1;
}
int len(int a) {
	int cnt = 0;
	while (a) {
		a /= 10;
		cnt++;
	}
	return cnt;
}
void solve(int t, int r) {
	if (t + len(r) > 100) return;
	if (check(r)) {
		cout << r ;
		for (int i = t - 1; i >= 0 ; i--) cout << ch[i];
		cout << "\n";
		c = 1;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		int w = (n*i + r);
		int u = w % 10;
		if (u == 0 || u == 1) {
			ch[t] = u;
			solve(t + 1, w / 10);
			if (c) return;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		c = 0;
		memset(ch, 0, sizeof(ch));
		cin >> n;
		if (n == 1) {
			cout << 1 << "\n"; continue;
		}
		solve(0, 0);
	}
}