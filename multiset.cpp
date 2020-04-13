#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	multiset <int> s;
	for (int i = 1; i <= 10; i++) {
		for (int k = 0; k < 3; k++) s.insert(i);
	}
	s.erase(3);
	for (auto a : s) cout << a << " ";
	system("pause");
}