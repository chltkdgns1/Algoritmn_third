#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int alpaCnt[26];
vector <int> v;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b; cin >> a >> b;
	int c; cin >> c;

	for (int i = 0; i < 26; i++) alpaCnt[i] += b[i] - 48;
	int n = a.length();

	set<unsigned long long> s;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		unsigned long long r = 0;
		for (int k = i; k < n; k++) {
			if (!alpaCnt[a[k] - 'a']) {
				cnt++;
				if (cnt > c) break;
			}
			r = (r + a[k] * (k - i + 1)) * 9991;
			s.insert(r);
		}
	}
	cout << s.size()<< "\n";
}