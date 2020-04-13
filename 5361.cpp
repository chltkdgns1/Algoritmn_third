#include <iostream>
using namespace std;
double arr[5] = { 350.34,230.90,190.55,125.30,180.90 };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		double ans = 0;
		for (int i = 0; i < 5; i++) {
			double a; cin >> a;
			ans += arr[i] * a;
		}
		printf("$%.2lf\n", ans);
	}
}