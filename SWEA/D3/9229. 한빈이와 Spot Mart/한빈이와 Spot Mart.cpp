#include <iostream>
using namespace std;
#define MAX 1003
int n, m;
int snack[MAX];
int solve() {
	fill(snack, snack + MAX, 0);
	int res = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> snack[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int t = snack[i] + snack[j];
			if (t > m) continue;
			res = max(res, t);
		}
	}
	if (res == 0) res = -1;
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "#" << tc << " " << solve() << "\n";
	}
}