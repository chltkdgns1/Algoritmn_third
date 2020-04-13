#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	map <int, int> m;
	m[1]++;
	for (auto a : m) cout << a.second << " ";
	m[1]--;
	cout << "\n\n";
	for (auto a : m) cout << a.second << " ";
	system("pause");
}