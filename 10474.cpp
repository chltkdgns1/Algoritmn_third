#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		int a, b; cin >> a >> b;
		if (!a && !b) break;
		cout << a / b << " " << a % b << " / " << b << "\n";
	}
}