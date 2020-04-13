#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct pung {
	int num, Da, Db;
	bool operator<(const pung& A)const {
		return abs(Db - Da) > abs(A.Db - A.Da);
	}
};

int main()
{
	while (true) {
		cout << "\n";
		int n, a, b, in, ia, ib, ans = 0;
		pung p[1001] = { 0 };
		cin >> n >> a >> b;
		if (n == 0 && a == 0 && b == 0) break;

		for (int i = 0; i < n; i++)
			cin >> p[i].num >> p[i].Da >> p[i].Db;

		sort(p, p + n);

		for (int i = 0; i < n; i++) {
			cout << p[i].num << " " << p[i].Da << " " << p[i].Db << "\n";
		}
		for (int i = 0; i < n; i++) {

			in = p[i].num, ia = p[i].Da, ib = p[i].Db;

			if (ia < ib) {
				if (a >= in) {
					ans += (in * ia), a -= in;
				}
				else {
					ans += (a * ia);
					ans += (in - a) * ib, b -= (in - a), a = 0;
				}
			}
			else {
				if (b >= in) {
					ans += (in * ib), b -= in;
				}
				else {
					ans += (b * ib);
					ans += (in - b) * ia, a -= (in - b), b = 0;
				}

			}
		}
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}