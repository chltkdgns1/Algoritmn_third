#include <iostream>
using namespace std;
#define mod 1000000007

typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b; cin >> a >> b;
	ll u = (a*b%mod*(b - 1) % mod + b) % mod*((a*b%mod*(b - 1) % mod + 1) % mod+ b) % mod / 2;
	cout << u - u / b << "\n";
	system("pause");
}