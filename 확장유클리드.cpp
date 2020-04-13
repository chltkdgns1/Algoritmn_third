#include <iostream>
#include <tuple>
using namespace std;

tuple <int, int, int> ext_gcd(int a, int b) {
	if (!b) return { a,1,0 };
	int  g, x, y;
	tie(g, x, y) = ext_gcd(b, a%b);
	cout << g << " " << x << " " << y << "\n";
	return { g,y,x - (a / b)*y };
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b; cin >> a >> b;
	int g, x, y; tie(g, x, y) = ext_gcd(a, b);
	cout << g << " " << x << " " << y << " ";
	system("pause");
}