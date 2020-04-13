#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
class Data {
public:
	int x, y;
};
bool cmp(Data &a, Data&b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}
map<int, ll> dp1, dp2;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	vector<Data> v(n + 1);
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		v[i] = { a,b };
	}
	sort(v.begin(), v.end(),cmp);
	dp1[v[1].x] = dp2[v[1].y] = m + abs(v[1].x - v[1].y);
	ll ans = dp1[v[1].x];
	for (int i = 2; i <= n; i++) {
		int x = v[i].x, y = v[i].y;
		ll len = abs(x - y) + m; 
		ll t = dp1[x] + len;
		dp1[x] = max(dp1[x],dp2[y] + len);
		dp2[y] = max(dp2[y],t);
		ans = max(ans, max(dp1[x], dp2[y]));
	}
	cout << ans << "\n";
}