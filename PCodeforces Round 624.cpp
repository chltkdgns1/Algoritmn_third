#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int n, d;
vector <int> res;
bool solve(int cnt, int depth, vector <int> v,int sum,int r) {
	if (sum == d && !r) {
		// 여기서 이제 트리를 생성해주면 됨
		map <int, vector<int>> m;
		m[0].push_back(1);
		map <int, int> mp;
		cout << "YES\n";
		int idx = 2;
		for (int i = 1; i < v.size(); i++) {
			int u = i - 1;
			for (int k = 0; k < v[i]; k++) {
				m[i].push_back(idx++);
				for (int z = 0; z < m[u].size(); z++) {
					int t = m[u][z];
					if (mp[t] < 2) {
						cout << t << " ", mp[t]++;
						break;
					}
				}
			}
		}
		cout << "\n";
		return 1;
	}

	for (int i = 1; i <= cnt; i++) {
		if (sum + i * depth > d || r - i < 0) break;
		v.push_back(i);
		if (solve(i*2, depth + 1, v, sum + i * depth, r - i)) return 1;
		v.pop_back();
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> d;
		vector <int> v;
		res.clear();
		if (!solve(1, 0, v, 0, n)) cout << "NO\n";
	}
}