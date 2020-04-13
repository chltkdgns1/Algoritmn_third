#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[100001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int k = 0;
	ll ans = 0;
	while (k < n) {
		if (k + 1 < n && a[k] < 0 && a[k + 1] < 0) 
			ans += a[k] * a[k + 1], k += 2;
		else if (k + 1 < n && a[k] < 0 && !a[k + 1]) k += 2;
		else if (a[k] < 0) ans += a[k], k++;
		else break;
	}
	while (k < n) {
		if (!a[k]) {k++; continue;}
		else if (a[k] == 1) ans += 1, k++;
		else break;
	}

	for (int i = n - 1; i >= k; i -= 2) {
		if (i == k) ans += a[k];
		else ans += a[i] * a[i - 1];
	}
	cout << ans << "\n";
}