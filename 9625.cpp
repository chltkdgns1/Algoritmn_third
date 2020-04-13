#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int k; cin >> k;
	int a = 1, b = 0;
	while (k--) {
		int t = a; a = 0;
		a += b, b += t;
	}
	cout << a << " " << b << "\n";
}