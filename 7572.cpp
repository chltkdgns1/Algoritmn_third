#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	int a = 'F' - 'A'; int b = 9;
	if (2013 < n) {
		for (int i = 2014; i <= n; i++) {
			a++; a %= 12; b++; b %= 10;
		}
		cout << char(a + 'A') << b << "\n";
	}
	else {
		for (int i = 2012; i >= n; i--) {
			a--; a = (a == -1 ? 11 : a);
			b--; b = (b == -1 ? 9 : b);
		}
		cout << char(a + 'A') << b << "\n";
	}
}