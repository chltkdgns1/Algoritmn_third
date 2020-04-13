#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	char a, b, c, d; cin >> a >> b >> c >> d;
	if (a == b && b == c && c == d) {
		cout << "?"; return 0;
	}
	if (a == b && c != d) {
		if (a == 'S') {
			if((c == 'R' || d == 'R')) cout << "TK";
			else cout << "?";
		}
		else if (a == 'R') {
			if (c == 'P' || d == 'P') cout << "TK";
			else cout << "?";
		}
		else if (a == 'P') {
			if ((c == 'S' || d == 'S')) cout << "TK";
			else cout << "?";
		}
	}
	else if (c == d && a != b) {
		if (c == 'S') {
			if ((a == 'R' || b == 'R')) cout << "MS";
			else cout << "?";
		}
		else if (c == 'R') {
			if (a == 'P' || b == 'P') cout << "MS";
			else cout << "?";
		}
		else if (c == 'P') {
			if ((a == 'S' || b == 'S')) cout << "MS";
			else cout << "?";
		}
	}
	else if (a == b && c == d) {
		if (a == 'S' && c == 'R') cout << "TK";
		if (a == 'R' && c == 'P') cout << "TK";
		if (a == 'P' && c == 'S') cout << "TK";
		if (a == 'R' && c == 'S') cout << "MS";
		if (a == 'P' && c == 'R') cout << "MS";
		if (a == 'S' && c == 'P') cout << "MS";
	}
	else cout << "?";
}