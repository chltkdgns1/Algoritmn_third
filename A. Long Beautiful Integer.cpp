#include <iostream>
#include <string>
using namespace std;

void Up(string &s) {
	int t = 1, idx = s.length() - 1;
	while (t) {
		int u = s[idx] - 48 + 1;
		t = (u >= 10 ? 1 : 0);
		s[idx] = u % 10 + 48;
		idx--;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	string s, res; cin >> s;

	int slen = s.length();
	for (int i = 0; i < m; i++) res += s[i];

	int idx = 0;
	for (int i = m; i < slen; i++) {
		if (res[idx] != s[i]) {
			if(res[idx] < s[i]) Up(res);
			break;
		}
		idx++;
		idx %= m;
	}

	string ans; idx = 0;
	while (ans.length() < n) {
		ans += res[idx++];
		idx %= m;
	}
	cout << ans.length() << "\n";
	cout << ans << "\n";
}