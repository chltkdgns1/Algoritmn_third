#include <iostream>
#include <algorithm>
using namespace std;
int d[4] = { 0,5,3,1 };
int q[4] = { 0,7,6,5 };
int main() {
	ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);
	int a[7]; for (int i = 1; i <= 6; i++) cin >> a[i];
	int res = a[6] + a[5] + a[4] + a[3] / 4 + (a[3] % 4 == 0 ? 0 : 1);
	a[3] %= 4; a[1] -= a[5] * 11;
	a[2] -= a[4] * 5;
	if (a[2] < 0) a[1] -= (-a[2]) * 4;
	a[2] = max(0, a[2]);
	a[2] -= d[a[3]];
	if (a[2] < 0) a[1] -= (-a[2]) * 4;
	a[1] -= q[a[3]];
	if (a[2] > 0) {
		res += a[2] / 9 + (a[2] % 9 == 0 ? 0 : 1);
		a[2] %= 9;
	}
	if (a[2] > 0) a[1] -= (36 - a[2] * 4);
	if (a[1] > 0) res += a[1] / 36 + (a[1] % 36 == 0 ? 0 : 1);
	cout << res << "\n";
}