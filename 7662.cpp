#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		multiset <int> set;
		int n; cin >> n;
		while (n--) {
			char a; int b;
			cin >> a >> b;
			if (a == 'I') set.insert(b);
			else {
				if (set.empty()) continue;
				if (b == -1) set.erase(set.begin());
				else set.erase(--set.end());
			}
		}
		if (set.empty()) cout << "EMPTY\n";
		else {
			auto s = set.begin();
			auto e = --set.end();
			cout << (*e) << " " << (*s) << "\n";
		}
	}
}