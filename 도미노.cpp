#include <iostream>
using namespace std;
int map[11][11];
int numbers[10];
int main(void) {
	int number;
	int d[10] = { 1, 0, 1, 0, 3, 0, 15, 0, 105, 0 };
	cin >> number;
	for (int i = 0; i < number; i++) {
		int temp;
		int a, b;
		cin >> temp;
		a = temp / 10;
		b = temp % 10;
		numbers[a]++;
		numbers[b]++;
	}
	long long result = 1;
	for (int i = 0; i < 10; i++)result *= d[numbers[i]];
	printf("%lld\n", result);
	return 0;
}
