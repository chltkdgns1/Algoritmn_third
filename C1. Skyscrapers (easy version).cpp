#include <iostream>
#include <string>
#include <set>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
ll a[500001], b[500001], c[500001], res[500001], t[500001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int idx = 1; t[idx] = 1;
	b[1] = a[1];
	for (int i = 2; i <= n; i++) {
		while (idx && a[t[idx]] > a[i]) idx--;
		b[i] =  ll(i - t[idx])*a[i] + b[t[idx]];
		t[++idx] = i;
	}
	idx = 1; t[idx] = n, c[n] = a[n];
	t[0] = n + 1;
	for (int i = n - 1; i >= 1; i--) {
		while (idx && a[t[idx]] > a[i]) idx--;
		c[i] = ll(t[idx] - i)*a[i] + c[t[idx]];
		t[++idx] = i;
	}
	
	ll mx = 0, cur;
	for (int i = 1; i <= n; i++) {
		if (mx < b[i] + c[i] - a[i]) {
			mx = b[i] + c[i] - a[i];
			cur = i;
		}
	}
	
	res[cur] = a[cur];
	for (int i = cur - 1; i >= 1; i--) res[i] = min(a[i], res[i + 1]);
	for (int i = cur + 1; i <= n; i++) res[i] = min(a[i], res[i - 1]);
	
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
}