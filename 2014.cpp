#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, m, a[101]; cin >> n >> m;
	priority_queue<ll> pq;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; pq.push(-a[i]);
 	}
	m--;
	while (m) {
		ll t = -pq.top(); pq.pop();
		for (int i = 0; i < n; i++) {
			if (a[i] * t <= 2147483647) pq.push(-a[i] * t);
			if (t % a[i] == 0) break;
		}
		m--;
	}
	cout << -pq.top() << "\n";
}