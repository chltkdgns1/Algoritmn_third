#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
bool isPrime[1000001];
typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<int>primes;
	for (int i = 2; i <= 1000000; i++) {
		if (!isPrime[i]) {
			primes.push_back(i);
			for (int k = 2; k*i <= 1000000; k++) {
				isPrime[i*k] = 1;
			}
		}
	}
	int n, a; cin >> n;
	map<int, int> indic, sindic[101], ansind;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int k = 0; k < primes.size(); k++) {
			if (primes[k] > a) break;
			if (!(a % primes[k])) {
				a /= primes[k]; indic[primes[k]]++;
				sindic[i][primes[k]]++, k--;
			}
		}
	}
	ll ans = 1;
	for (auto a : indic) {
		ans *= pow(a.first, a.second / n);
		ansind[a.first] = a.second / n;
	}
	ll cans = 0;
	for (int i = 0; i < n; i++) {
		for (auto a : ansind) {
			int t = sindic[i][a.first] - a.second;
			if (t < 0) cans += -t;
		}
	}
	cout << ans << " " << cans << "\n";
}