#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s; int k = -1,t = 0;  cin >> s;
	for (int i = 0; i < s.length(); i++) k = (s[i] == '#' ? i : k);
	for (int i = k + 1; i < s.length(); i++) t += s[i] == ')' ? 1 : -1;
	stack <char> st; vector <int> res;
	if (t < 0) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < s.length(); i++) {
		if (st.empty() && (s[i] == '#' || s[i] == ')')) {
			cout << -1;
			return 0;
		}
		if (s[i] == ')') st.pop();
		else if (s[i] == '#') {
			if (i != k) res.push_back(1), st.pop();
			else {
				int a = st.size();
				while (st.size() != t) st.pop();
				if (a - t <= 0) {
					cout << -1;
					return 0;
				}
				res.push_back(a - t);
			}
		}
		else st.push(s[i]);
	}
	if (!st.empty()) cout << -1;
	else for (auto a : res) cout << a << "\n";
}