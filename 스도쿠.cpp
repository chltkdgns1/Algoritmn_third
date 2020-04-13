#include <iostream>
using namespace std;
char map[10][10];
bool backTraking(int x, int y,int n) {
	for (int i = 0; i < 9; i++) 
		if (map[i][x] - '0' == n || map[y][i] - '0' == n) return 0;	
	int s = x / 3 * 3, e = s + 3;
	int l = y / 3 * 3, r = l + 3;
	for (int i = s; i < e; i++) 
		for (int k = l; k < r; k++) 
			if (map[k][i] - '0' == n) return 0;
	return 1;
}
bool solve(int x, int y) {
	if (y > 8) {
		for (int i = 0; i < 9; i++) cout << map[i] << "\n";
		exit(0);
	}
	if (map[y][x] != '0') solve((x + 1) % 9, y + (x + 1) / 9);
	else {
		for (int i = 1; i <= 9; i++) {
			if (backTraking(x, y, i)) {
				map[y][x] = i + '0';
				solve((x + 1) % 9, y + (x + 1) / 9);
				map[y][x] = '0';
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 9; i++) cin >> map[i];
	solve(0, 0);	
}