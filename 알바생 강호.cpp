#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int>v(n );
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	ll a = 0, b = 0;
	for (int i = 0; i < n; i++) a += max(0,v[i] - i);
	for (int i = 0; i < n; i++) b += max(0, v[n - 1 - i] - i);
	cout << max(a, b) << "\n";
}