#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int minValue = INF, maxValue = -INF;
		int n, x;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> x;
			minValue = min(minValue, x);
			maxValue = max(maxValue, x);
		}
		cout << minValue << ' ' << maxValue << "\n";
	}
}