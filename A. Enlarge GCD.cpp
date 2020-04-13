#include <iostream>
using namespace std;

int a[300001];
int gcd(int a, int b) {
	if (!(a % b)) return b;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int t = a[0];
	for (int i = 1; i < n; i++) {
		int u = gcd(t, a[i]);
		t = u == 1 ? a[i] : u;
	}
	cout << t << "\n";
	system("pause");
}