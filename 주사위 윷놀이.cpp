#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int b[] = { 10,13,16,19,25};
int c[] = { 30,28,27,26,25};
int d[] = { 25,30,35,40,0};
int e[] = { 20,22,24,25};
int a[22], t[10], st[10];
vector <int> v[5];
int maps[5][25];
int start() {
	int ans = 0, chr[6], state[6];
	memset(chr, 0, sizeof(chr));
	memset(state, 0, sizeof(state));
	memset(maps, 0, sizeof(maps));
	for (int i = 0; i < 10; i++) {
		int c = t[i],target = st[i];
		int &ct = chr[target];
		int &st = state[target];
		if (st == 4 && ct == 4) continue;
		if (!st && ct == 21) continue;
		int lct = ct, lst = st;
		int gct = ct + c, gst = st;
		if (!gst) { // state 가 0일 경우에 
			if (gct < 20 && !(gct % 5)) {
				gst = gct / 5;
				gct = 0;
			}	
		}
		else if (gst != 4 && gct >= v[gst].size() - 1) {
			gct -= (v[gst].size() - 1), gst = 4;
		}
		gct = min(gct, int(v[gst].size()) - 1);
		if (maps[gst][gct]) break;
		if (gst == 4 && gct == 3 && maps[0][20]) break;;
		if (!gst && gct == 20 && maps[4][3]) break;
		ct = gct, st = gst;
		maps[lst][lct] = 0;
		if (st == 4 && ct == 4) continue;
		if (!st && ct == 21) continue;
		maps[st][ct] = 1;
		ans += v[st][ct];
	}
	return ans;
}
int ans;
void solve(int t) {
	if (t == 10) {
		ans = max(ans, start());
		return;
	}
	for (int i = 1; i <= 4; i++) {
		st[t] = i;
		solve(t + 1);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 10; i++) cin >> t[i];
	for (int i = 0; i < 21; i++) v[0].push_back(i * 2);
	v[0].push_back(0);
	for (int i = 0; i < 5; i++)
		v[1].push_back(b[i]), v[3].push_back(c[i]), v[4].push_back(d[i]);
	for (int i = 0; i < 4; i++) v[2].push_back(e[i]);
	solve(0);
	cout << ans << "\n";
}

