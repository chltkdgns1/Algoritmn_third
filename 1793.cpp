#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dp[251][3];
string Plus(string a,string b){
	int up = 0, al = a.length() - 1, bl = b.length() - 1;
	string ans;
	while (al >= 0 && bl >= 0) {
		int x = a[al] - '0', y = b[bl] - '0';
		ans += (x + y + up) % 10 + '0';
		up = (x + y + up) / 10;
		al--, bl--;
	}
	while (al >= 0) {
		ans += (a[al] - '0' + up) % 10 + '0';
		up = (a[al] - '0' + up) / 10; al--;
	}
	while (bl >= 0) {
		ans += (b[bl] - '0' + up) % 10 + '0';
		up = (b[bl] - '0' + up) / 10; bl--;
	}
	if(up) ans += up + '0';
	reverse(ans.begin(), ans.end());
	return ans;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; dp[1][0] = dp[2][0] = dp[2][1] = dp[2][2] = "1";
	for (int i = 3; i <= 250; i++) {
		dp[i][0] = Plus(Plus(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
		dp[i][1] = Plus(Plus(dp[i - 2][0], dp[i - 2][1]), dp[i - 2][2]);
		dp[i][2] = Plus(Plus(dp[i - 2][0], dp[i - 2][1]), dp[i - 2][2]);
	}
	while (cin >> n) {
		if (!n) cout << 1 << "\n";
		else cout << Plus(Plus(dp[n][0],dp[n][1]),dp[n][2]) << "\n";
	}
}