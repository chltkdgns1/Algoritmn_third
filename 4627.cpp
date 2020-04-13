#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <string.h>
#include <string>
using namespace std;

const int MAX_N = 20;
const int MAX = MAX_N * MAX_N * 2 + 2;
vector<int> eg[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
int source = MAX - 2;
int sink = MAX - 1;

void addEdge(int u, int v, int cap) {
	c[u][v] = cap;
	eg[u].push_back(v);
	eg[v].push_back(u);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t,cnt=1; cin >> t;
	while (t--) {
		memset(c, 0, sizeof(c)), memset(f, 0, sizeof(f));
		for (int i = 1; i < MAX; i++) eg[i].clear();

		int n, d; scanf_s("%d %d\n", &n, &d);
		int ans = 0;
		int sz = -1;

		for (int i = 0; i < n; i++) {
			for(int k =0;;k++){
				char c = getchar();
				if (c == '\n') {if(!i) sz = k; break; }

				int idx = (i * MAX_N + k) * 2;
				if(c != '0') addEdge(idx, idx + 1, c - '0');
			}
		}

		for (int i = 0; i < n; i++) {
			for (int k = 0; k < sz; k++) {
				char c = getchar();

				int u = (i * 20 + k) * 2;
				if (c == 'L') addEdge(source, u, 1), ans++;

				for (int z = -d; z <= d; z++) {
					for (int q = -d; q <= d; q++) {
						if (abs(z) + abs(q) > d) continue;

						int v = ((i + z) * 20 + k + q) * 2;
						if (i + z < 0 || i + z >= n
							|| k + q < 0 || k + q >= sz) v = sink;
						addEdge(u + 1, v, 1e9);
					}
				}
			}
			getchar();
		}

		while (1) {
			queue <int> q; q.push(source);
			int d[MAX];
			fill(d, d + MAX, -1);
			while (!q.empty()) {
				int from = q.front();
				q.pop();

				for (auto to : eg[from]) {
					if (c[from][to] - f[from][to] > 0 && d[to] == -1) {
						d[to] = from;
						q.push(to);
					}
				}
			}

			if (d[sink] == -1) break;

			for (int i = sink; i != source; i = d[i]) {
				++f[d[i]][i];
				--f[i][d[i]];
			}
			ans--;
		}
		cout << "Case #" << cnt++ << ": ";
		if (!ans) cout<<"no lizard was left behind.\n";
		else if (ans == 1) cout<<"1 lizard was left behind.\n";
		else cout << ans << " lizards were left behind.\n";
	}
	system("pause");
}