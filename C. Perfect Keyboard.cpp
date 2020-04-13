#include <iostream>
#include <string>
#include <set>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
pair<int, int> a[1001];
int v[1001], n;
pair<ll,vector<int>> solve(int s, int e,int index) {
	if (index == n) {
		vector <int> v(n);
		return { 0,v };
	}
	int t = a[index].second;
	ll x, y;
	pair<ll, vector<int>> ans;
	if (s <= t && t<= e) {
		pair<ll, vector<int>> aa = solve(s, t - 1, index + 1);
		pair<ll, vector<int>> bb = solve(t + 1, e, index + 1);

		x = aa.first = aa.first + (e - t + 1)*a[index].first;
		y = bb.first = bb.first + (t - s + 1)*a[index].first;

		if (x <= y) {
			for (int i = s; i <= t; i++) bb.second[i] = a[index].first;
			return bb;
		}
		else {
			for (int i = t; i <= e; i++) aa.second[i] = a[index].first;
			return aa;
		}
	}
	else ans = solve(s, e, index + 1);
	return ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		a[i] = { v[i],i };
	}
	sort(a, a + n);
	pair<ll, vector<int>> bb = solve(0, n - 1, 0);
	for (auto a : bb.second) cout << a << " ";
	system("pause");
}
