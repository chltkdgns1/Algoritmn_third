#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
ll  dp[1 << 15][101];
ll gcd(ll a, ll b) {
	if (!(a % b)) return b;
	return gcd(b, a%b);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector <int> remain(n), len(n);
	vector <string> v(n);
	ll sqd[51]; 
	for (int i = 0; i < n; i++) {
		cin >> v[i]; len[i] = v[i].length();
	}
	int m; cin >> m;
	if (m == 1) {
		cout << "1/1" << "\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < v[i].length(); k++) {
			remain[i] = (remain[i] * 10 + v[i][k] - 48) % m;
		}
	}
	sqd[0] = 1;
	for (int i = 1; i <= 50; i++) {
		sqd[i] = sqd[i - 1] * 10;
		sqd[i] %= m;
	}
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i++) {
		for (int z = 0; z < m; z++) {
			for (int k = 0; k < n; k++) {
				if ((i & (1 << k))) continue;
				int t = ((z*sqd[len[k]]) % m + remain[k]) % m;
				dp[(i | (1 << k))][t] += dp[i][z];
			}
		}
	}
	ll t = dp[(1 << n) - 1][0],q = 1;
	if (!t) {
		cout << "0/1";
		return 0;
	}
	for (int i = n; i >= 1; i--) q *= i;
	ll r =  gcd(t, q);
	cout << t / r << "/" << q / r << "\n";
}