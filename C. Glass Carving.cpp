#include <iostream>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int w, h, n; cin >> w >> h >> n;

	set <int> ws, hs;
	map <ll,int> wm, hm;
	ws.insert(0), ws.insert(w), hs.insert(0), hs.insert(h);
	wm[w]++, hm[h]++;

	char a; int b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == 'H') {
			hs.insert(b);
			auto it = hs.find(b),s = (--it), e = ++(++it);
			int t = (--hm[(*e) - (*s)]);
			if (!t) hm.erase((*e) - (*s));
			hm[b - (*s)]++, hm[(*e) - b]++;
			cout << (*(--hm.end())).first * (*(--wm.end())).first << "\n";
		}
		else {
			ws.insert(b);
			auto it = ws.find(b), s = (--it), e = ++(++it);
			int t = (--wm[(*e) - (*s)]);
			if (!t) wm.erase((*e) - (*s));
			wm[b - (*s)]++, wm[(*e) - b]++;
			cout << (*(--hm.end())).first * (*(--wm.end())).first << "\n";
		}
	}
}