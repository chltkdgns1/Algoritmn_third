#include <iostream>
#include <algorithm>
using namespace std;

int a[100001],dp[100001], ch[100001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

		
	a[0] = a[1], a[n + 1] = a[n];
	for (int i = 1; i <= n; i++) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) ch[i] = 3;
		else if (a[i] < a[i - 1] && a[i] < a[i + 1]) ch[i] = 4;
		else if (a[i] < a[i + 1]) {
			if (i != 1 && ch[i - 1] == 1) ch[i] = 4;
			else ch[i] = 2;
		}
		else if (a[i] > a[i + 1]) {
			if (i != 1 && ch[i - 1] == 2) ch[i] = 3;
			else ch[i] = 1;
		}
		else if (a[i] > a[i - 1]) ch[i] = 2;
		else if (a[i] < a[i - 1]) ch[i] = 1;
		else ch[i] = ch[i - 1];
	}

	for (int i = n; i >= 2; i--) {
		if (a[i] == a[i - 1]) ch[i - 1] = ch[i];
	}

	for (int i = 1; i <= n; i++) cout << ch[i] << " ";
	system("pause");
}