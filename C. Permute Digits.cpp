#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
int d[10];
string a, b;

string solve(int s, bool ch) {
	if (s == a.length()) return "-";
	string t, u;
	for (int i = b[s] - 48; i >= ch; i--) {
		if (d[i]) {
			if (i == b[s] - 48) {
				d[i]--;
				u += (i + 48);
				u += solve(s + 1, 0);
				d[i]++;
			}
			else {
				d[i]--;
				t += (i + 48);
				for (int k = 9; k >= 0; k--) {
					for (int z = 0; z < d[k]; z++)  t += (k + 48);
				}
				break;
			}
		}
	}
	if (u.size() == 1 || !u.size()) return t;
	else return u;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b;
	for (auto c : a) d[c - 48]++;
	if (a.length() < b.length()) {
		for (int i = 9; i >= 0; i--) {
			for (int k = 0; k < d[i]; k++) cout << i;
		}
	}
	else {
		string r = solve(0, 1);
		if (r.back() == '-') r.pop_back();
		cout << r;
	}
}