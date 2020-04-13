#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class p {
public:
	int a;
	pair<int, int> b;
};
bool cmp(p &a, p &b) {
	if (a.a == b.a) {
		return a.b < b.b;
	}
	return a.a < b.a;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		vector <p> v;
		for (int i = 0; i < 5; i++) {
			int a, b;
			scanf("%d:%d", &a, &b);
			int x = a % 12;
			int t = 60 * x + b, u = b * 12;
			int w = abs(t - u);
			int q = min(w, 720 - w);
			v.push_back({ q ,{a,b}});
		}
		sort(v.begin(), v.end(),cmp);
		printf("%02d:%02d\n", v[2].b.first, v[2].b.second);
	}
}