#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef long long ll;

class Data {
public:
	int a, b, c;
};

int lecSize(vector <Data>&v,int z) {
	int maxx = 0, minx = 1e9, maxy = 0, miny = 1e9;
	for (int k = 0; k < v.size(); k++) {
		if (z == k) continue;
		int a = v[k].a, b = v[k].b;
		maxx = max(maxx, a); minx = min(minx, a);
		maxy = max(maxy, b); miny = min(miny, b);
	}
	int t = (maxx - minx) * 2 + (maxy - miny) * 2;
	return t;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<Data> v;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ a,b,c});
	}
	int hvt = 0;
	if (!lecSize(v, -1)) {
		cout << 0 << "\n";
		return 0;
	}

	for(int i=1;i<= n;i++){
		int leave = 1e9, idx;
		for (int z = 0; z < v.size(); z++) {		
			ll t = lecSize(v, z);
			if (leave > t - (hvt + v[z].c)) {
				leave = t - (hvt + v[z].c);
				idx = z;
			}	
			if (leave <= 0) {
				cout << i << "\n";
				return 0;
			}
		}
		hvt += v[idx].c;
		v.erase(v.begin() + idx);
	}
}











































































