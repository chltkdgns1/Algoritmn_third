#include<iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>v, e[12];
char s[200];
int n;
bool backTracking(int idx) {
	int cnt = 1;
	for (auto a : e[idx]) {
		int res = 0;
		for (int i = cnt; i <= idx; i++) res += v[i];
		if (s[a] == '+' && res <= 0) return 0;
		if (s[a] == '0' && res != 0) return 0;
		if (s[a] == '-' && res >= 0) return 0;
		cnt++;
	}
	return 1;
}
void solve(int idx) {
	if (n < idx) {
		for (int i = 1; i <= n; i++) cout << v[i] << " ";
		exit(0);
	}
	for (int i = -10; i <= 10; i++) {
		v[idx] = i;
		if (backTracking(idx)) {
			solve(idx + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	 cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int k = i, t = n - 1, z = 1; z <= i; k += t, t--, z++) {
			e[i].push_back(k);
		}
	}
	cin >> s + 1; 
	solve(1);
}