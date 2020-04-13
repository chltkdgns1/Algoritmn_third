#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int a[10] = { 1,1,1,1,1,0,0,0,0,0 };

	int cnt = 0;
	do {
		cnt++;
	} while (prev_permutation(a, a + 10));
	cout << cnt << "\n";
	system("pause");
}