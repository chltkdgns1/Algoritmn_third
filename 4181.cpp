#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e5;
int n;
typedef pair<int, int> Segment;
Segment point[MAX + 1];
ll ccw(const Segment &origin, const Segment &a, const Segment &b) {
	Segment first = { a.first - origin.first, a.second - origin.second };
	Segment second = { b.first - origin.first, b.second - origin.second };
	return (ll)first.first * second.second - (ll)first.second * second.first;
}

bool cmp(const Segment &a, const Segment &b) {
	auto ret = ccw(point[0], a, b);
	if (ret == 0) {
		return a.second > b.second;
	}
	return ret > 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int count = 0;
	int x, y;
	char c;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> c;
		if (c == 'N') continue;
		point[count++] = { x, y };
	}
	swap(point[0], *min_element(point, point + count));
	sort(point + 1, point + count, cmp);
	cout << count << "\n";
	for (int j = 0; j < count; ++j) {
		cout << point[j].first << " " << point[j].second << "\n";
	}
	return 0;
}