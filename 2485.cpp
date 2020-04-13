#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
	if (!(a % b)) return b;
	return gcd(b, a%b);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int> v(n), e;
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int t = v[1] - v[0];
	for (int i = 2; i < n; i++) t = gcd(t, v[i] - v[i - 1]);
	int w = (v[n - 1] - v[0]) / t + 1 - n;
	cout << w;
}