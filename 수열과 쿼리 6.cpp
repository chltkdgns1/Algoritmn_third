#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100001], ans[100001], cnt[100001], table[100001],res;

pair<pair<int,int>,int> sq[100001];
pair<int, int> q[100001];

void add(int x) {
	if (cnt[x] != 0) table[cnt[x]]--;
	cnt[x]++; table[cnt[x]]++;
	res = max(res, cnt[x]);
}

void erase(int x) {
	table[cnt[x]]--;
	if (cnt[x] == res && !table[cnt[x]]) res--;
	cnt[x]--;
	table[cnt[x]]++;
}


void qurey(pair<int,int> s,pair<int,int> e) {
	int sl = s.first, sr = s.second;
	int el = e.first, er = e.second;
	for (int i = sl - 1; i >= el; i--) add(a[i]);
	for (int i = sr + 1; i <= er; i++) add(a[i]);
	for (int i = sl; i < el; i++) erase(a[i]);
	for (int i = sr; i > er; i--) erase(a[i]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,b; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int m; cin >> m;
	int sqrtn = sqrt(n);
	for (int i = 1; i <= m; i++) {
		cin >> q[i].first >> q[i].second;
		sq[i] = { {q[i].first / sqrtn, q[i].second} , i };
	}
	sort(sq + 1, sq + m + 1);

	for (int i = 1; i <= m; i++) {
		qurey(q[sq[i - 1].second], q[sq[i].second]);
		ans[sq[i].second] = res;
	}

	for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
}