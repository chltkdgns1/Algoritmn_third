#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	bool ch = 0;
	for (int i = 1; i <= 5; i++) {
		string a; cin >> a;
		for (int k = 0; k < a.length() - 2; k++) {
			if (a[k] == 'F' && a[k + 1] == 'B' && a[k + 2] == 'I') {
				cout << i << " "; ch = 1;
				break;
			}
		}
	}
	if (!ch) cout << "HE GOT AWAY!";
}