#include <cstdio>
#include<iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 2;

int t, n, p;
char s[N];
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> s + 1;
		s[n] = '>', p = 0;
		for (int i = 1; i <= n; i++)
			if (s[i] == '>') {
				for (int j = n - i + 1; j <= n - p; j++)
					printf("%d ", j);
				p = i;
			}
		printf("\n");
		s[n] = '<'; p = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '<') {
				for (int j = i; j > p; j--)
					printf("%d ", j);
				p = i;
			}
		}
		printf("\n");
	}
}