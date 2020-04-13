#include <iostream>
using namespace std;

typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, k; cin >> n >> k;
	ll a[100001], sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		if (sum > k) {
			cout << i;
			return 0;
		}
	}
	for (int i = n; i >= 1; i--) {
		sum += a[i];
		if (sum > k) {
			cout << i;
			break;
		}
	}
}