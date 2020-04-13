#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	long long a, b, c, d;
	for (; t--;) {
		cin >> a >> b;
		c = a / (b + 1);
		d = a - c;
		c = b * c*(c + 1) / 2;
		d = d * (d + 1) / 2;
		printf("%lld\n", c + d);
	}
	system("pause");
}