#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, m, x, y, t,u,dir = 1; cin >> m >> n >> x >> y >> t;
	while (t > 0) {
		if (dir == 1) {
			u = min(m - x, n - y);
			if (t - u < 0) u = t;
			t -= u, x += u, y += u;
			if (x == m && y == n) dir = 3;
			else if (y == n) dir = 4;
			else dir = 2;
		}
		else if (dir == 2){
			u = min(x, n - y);
			if (t - u < 0) u = t;
			t -= u, x -= u, y += u;
			if (!x && y == n) dir = 4;
			else if (y == n) dir = 3;
			else dir = 1;
		}
		else if (dir == 3) {
			u = min(x, y);
			if (t - u < 0) u = t;
			t -= u, x -= u, y -= u;
			dir++;
			if (!x && !y) dir = 1;
			else if (!y) dir = 2;
			else dir = 4;
		}
		else {
			u = min(m - x, y);
			if (t - u < 0) u = t;
			t -= u, x += u, y -= u;
			if (!y && x == m) dir = 2;
			else if (!y) dir = 1;
			else dir = 3;
		}
	}
	cout << x << " " << y << "\n";
}