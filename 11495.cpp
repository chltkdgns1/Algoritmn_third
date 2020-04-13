#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define INF 987654321
int N, M;
int src, sink;
int arr[51][51];
int dy[] = { -1,0,0,1 };
int dx[] = { 0,-1,1,0 };
vector<vector<int>> adj;
int f[2555][2555], C[2555][2555];
void add_edge(int u, int v, int c) {
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
	C[u][v] = c;
}

int max_flow() {
	int ret = 0;
	while (1) {
		queue<int> q;
		vector<int> par(N*M + 10, -1);
		q.push(src);
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (int next : adj[here]) {
				if (C[here][next] - f[here][next] > 0 && par[next] == -1) {
					par[next] = here;
					q.push(next);
				}
			}
		}
		if (par[sink] == -1) break;
		int flow = INF;
		for (int i = sink; i != src; i = par[i]) {
			cout << i << " ";
			flow = min(flow, C[par[i]][i] - f[par[i]][i]);
		}
		cout << "\n";
		for (int i = sink; i != src; i = par[i])
			f[par[i]][i] += flow, f[i][par[i]] -= flow;
		ret += flow;
	}
	return ret;
}

int main() {
	int T;
	scanf_s("%d", &T);
	while (T--) {
		int sum = 0;
		memset(C, 0, sizeof C);
		memset(f, 0, sizeof f);
		scanf_s("%d%d", &N, &M);
		adj = vector<vector<int>>(N*M + 10, vector<int>());
		src = N * M + 8, sink = N * M + 9;
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++) scanf_s("%d", &arr[n][m]), sum += arr[n][m];
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if ((!(n & 1) && !(m & 1)) || ((n & 1) && (m & 1))) { //µÑ´Ù Â¦ or È¦ÀÎ °æ¿ì
					add_edge(src, n*M + m, arr[n][m]);
					for (int i = 0; i < 4; i++) {
						int ny = n + dy[i], nx = m + dx[i];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
						add_edge(n*M + m, ny*M + nx, INF);
					}
				}
				else add_edge(n*M + m, sink, arr[n][m]);
			}
		}
		int ans = max_flow();
		int plus = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if ((!(n & 1) && !(m & 1)) || ((n & 1) && (m & 1))) //µÑ´Ù Â¦ or È¦ÀÎ °æ¿ì
					plus += C[src][n*M + m] - f[src][n*M + m];
				else plus += C[n*M + m][sink] - f[n*M + m][sink];
			}
		}
		printf("%d\n", ans + plus);
	}
	system("pause");
	return 0;
}
