#include <iostream>
#include <string>
using namespace std;
int main() {
	int a; cin >> a;
	if (a == 1) cout << 1, exit(0);
	string s = "110", r, t;
	for (int i = 0; i < a - 2; i++) r += '1', t += '0';
	cout << r + s + t << "\n";
}