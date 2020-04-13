#include<iostream>
using namespace std;
typedef long long ll;
ll n, b = 998244353, a = 1;
int main() {
	cin >> n; a = n;
	for (int i = 2; i <= n; i++) a = (a - 1)*i%b;
	cout << a; 
}