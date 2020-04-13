#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int ans = 0, cnt = 0;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == '(' && s[i + 1] == '(') cnt++;
		else if (s[i] == ')' && s[i + 1] == ')') ans += cnt;
	}
	cout << ans << "\n";
}