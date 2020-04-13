#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Data {
public:
	int a, b, x, y;
	bool ch;
};
int tree[100001], lazy[100001];
vector <Data> v;
bool cmp(const Data&a, const Data&b) {
	return a.a < b.a;
}
void update(int s, int e, int n,int l, int r, int t) {
	if (e < l || r < s) return;
	if (l <= s && e <= r) lazy[n] += t;
	else {
		int m = (s + e) / 2;
		update(s, m, n * 2, l, r, t), update(m + 1, e, n * 2 + 1, l, r, t);
	}
	if (lazy[n]) tree[n] = e - s + 1;
	else{
		if (s == e) tree[n] = 0;
		else tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, b, x, y; cin >> n;
	int t = 1 << int(ceil(log2(30000)));
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> x >> y;
		v.push_back({ a,b,x,y,1});
		v.push_back({ x,b,a,y,0 });
	}
	sort(v.begin(), v.end(), cmp);
	int dis = v[0].a, res = 0;
	for (int i = 0; i < v.size(); i++) {
		res += tree[1] * (v[i].a - dis);
		dis = v[i].a;
		if (v[i].ch) update(0, t - 1, 1, v[i].b, v[i].y - 1, 1);
		else update(0, t - 1, 1, v[i].b, v[i].y - 1, -1);
	}
	cout << res << "\n";
}