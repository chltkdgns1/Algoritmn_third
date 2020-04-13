#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solve(string &s, int a, int b,int t){
	if (t == 2) return 2;
	int ch = 2, k = 0;
	while (a <= b) {
		if (s[a] != s[b]) {
			k++;
			if (s[a + 1] == s[b]) ch = min(ch, solve(s, a + 1, b, t + 1));
			if (s[a] == s[b - 1]) ch = min(ch, solve(s, a, b - 1, t + 1));
			if (!ch) return 1;
			else return 2;	
		}
		a++, b--;
	}
	if (!k) return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		cout << solve(s, 0, s.length() - 1, 0) << "\n";
	}
}