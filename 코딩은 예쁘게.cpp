#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];

int cal(int s, int e, int k) {
	int cnt = 0;
	for (int i = s; i <= e; i++) {
		a[i] += k;
		cnt += !a[i] ? 1 : 0;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,b; cin >> n;
	int res = 0, cnt = 0;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b, a[i] -= b, cnt += !a[i] ? 1 : 0;

	while (cnt < n) {
		int l = -1e9, r = 1e9, s = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < 0) {
				if (r != 1e9) {
					cnt += cal(s, i - 1, -r);				
					res += r, r = 1e9 ,l = -1e9;			
					s = i;
				}
				l = max(a[i], l);
			}
			else if (!a[i]) {
				if (l != -1e9 || r != 1e9) {
					cnt += cal(s, i - 1, (l != -1e9 ? -l : -r));
					res += (l != -1e9 ? -l : r);
				}
				l = -1e9, r = 1e9;
				s = i + 1;
			}
			else {
				if (l != -1e9) {
					cnt += cal(s, i - 1, -l);
					res += -l, r = 1e9, l = -1e9;
					s = i;
				}
				r = min(a[i], r);
			}
		}
		if (l != -1e9 || r != 1e9) {
			cnt += cal(s, n - 1, (l != -1e9 ? -l : -r));
			res += (l != -1e9 ? -l : r);
		}
	}
	cout << res << "\n";
}