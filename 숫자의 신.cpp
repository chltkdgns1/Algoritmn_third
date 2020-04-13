#include <iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
bool cmp(string&a, string&b) {
	return a + b > b + a;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	vector<ll>v(n);
	vector<string>e;
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < k - n; i++) e.push_back(to_string(v[0]));
	for (auto a : v) e.push_back(to_string(a));
	sort(e.begin(), e.end(),cmp);
	for (auto a : e) cout << a ;
}