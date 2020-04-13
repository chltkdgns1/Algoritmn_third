#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using  namespace std;

int c[101][101]; // cap 지나갈수 있는 용량
int f[101][101]; // 이미 지나간 용량
vector <int> v[101];


int spfa(int s,int n) {
	vector <int> visit(n + 1,0), dist(n + 1,1e9);
	queue <int> q; q.push(s);
	visit[s] = 1; dist[s] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto a : v[x]) {
			if(c[x][a] - f[x][a] > 0 && dist)
		}
	}
}

int getMaxFlow(int s,int e) {

	int maxflow = 0;
	while (spfa(s)) {
		int dir[101];
		memset(dir, -1, sizeof(dir));
		queue <int> q; q.push(s);

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto a : v[x]) {
				if (c[x][a] - f[x][a] > 0 && dir[a] == -1) {
					q.push(a);
					dir[a] = x;
					if (a == e) break;
				}
			}
		}

		if (dir[e] == -1) break;

		int flow = 1e9;
		for (int i = e; i != s; i = dir[i]) 
			flow = min(flow,c[dir[i]][i] - f[dir[i]][i]);

		for (int i = e; i != s; i = dir[i]) {
			f[dir[i]][i] += flow;
			f[i][dir[i]] -= flow;
		}
		maxflow += flow;
	}
	return maxflow;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {

	}

	for (int i = 0; i < m; i++) {
		int a, b, d; cin >> a >> b >> d;
		v[a].push_back(b);
		v[b].push_back(a);
		c[a][b] = c[b][a] = d;
	}
	
	spfa(1, n);
	system("pause");
}