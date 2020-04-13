#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define mod 998244353
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<ll>v(n), e(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) cin >> e[i];
	for (int i = 0; i < n; i++) v[i] *= (i + 1)*(n - i);
	sort(v.begin(), v.end()), sort(e.rbegin(), e.rend());

	ll ans = 0;
	for (int i = 0; i < n; i++) ans = (ans +  v[i] % mod * e[i]) % mod;
	cout << ans << "\n";
	system("pause");
}