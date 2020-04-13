#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];
int main() {
	int n, m;
	int a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) arr[i][j] = 1e9;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[a][b] = min(arr[a][b], c);
	}
	for (int m = 1; m <= n; m++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (arr[s][e] > arr[s][m] + arr[m][e])
					arr[s][e] = arr[s][m] + arr[m][e];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1e9) arr[i][j] = 0;
			cout << arr[i][j] << " ";
		}
		cout <<"\n";
	}
}