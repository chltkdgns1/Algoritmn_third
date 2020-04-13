#include <iostream>
#include <string>
using namespace std;

int pi[1000001];


int gcd(int a, int b) {
	if (!(a % b)) return b;
	return gcd(b, a%b);
}

void getPi(string a) {
	int c = 0;
	for (int i = 1; i < a.length(); i++) {
		if (a[i] == a[c]) pi[i] = ++c;
		else if (c) {
			c = pi[c - 1];
			i--;
		}
	}
}

int find(string &a, string &b) {
	int c = 0, res = 0;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == a[c]) {
			c++;
			if (c == a.length()) res++;
		}
		else if (c) {
			c = pi[c - 1];
			i--;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;

	string a, b; int r = 0;
	for (int i = 0; i < n; i++) {
		char b; cin >> b; a += b;
	}
	for (int i = 0; i < n; i++) {
		char c; cin >> c, b += c;
	}
	if (a == b) r++;
	a += a;
	getPi(b);
	int t = find(b, a) - r;
	int u = gcd(n, t);
	cout << t / u << "/" << n / u;
}