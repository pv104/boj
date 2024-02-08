#include <iostream>
#define N 10
#define MAX 102
using namespace std;
int n, r, c;
int board[MAX][MAX];
int solve() {
	cin >> n;
	for (int tc = 0; tc < n; tc++) {
		cin >> r >> c;
		for (int i = r; i < r + N; i++) {
			for (int j = c; j < c + N; j++) {
				board[i][j] = 1;
			}
		}
	}
	int res = 0;
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			res += board[i][j];
		}
	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cout << solve();
}