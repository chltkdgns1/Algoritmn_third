#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; string s; cin >> s >> n;
	for (int i = 2; i <= n - 1; i++) {
		int t = 0;
		for (int k = 0; k < s.length(); k++) {
			t = t * 10 + s[k] - 48;
			t %= i;
		}
		if (!t) {
			cout << "BAD "<<i << "\n";
			return 0;
		}
	}
	cout << "GOOD";
}