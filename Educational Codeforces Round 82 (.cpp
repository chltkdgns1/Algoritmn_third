#include <iostream> 
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll t; cin >> t;
	while (t--)
	{
		ll n, a, b;
		cin >> n >> a >> b;
		ll m = (n + 1) / 2;
		cout << m + max(n - m, (m - 1) / a * b) << endl;
	}
}