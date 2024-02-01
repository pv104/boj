#include <iostream>
using namespace std;
#define MAX 16
int solve() {

	int n, m;
	int board[MAX][MAX];
	int sum[MAX][MAX];
	for (int i = 0; i < MAX; i++) {
		fill(sum[i], sum[i] + MAX, 0);
		fill(board[i], board[i] + MAX, 0);
	}

	int res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (j == 0) 
				sum[i][j] = board[i][j];
			else sum[i][j] = sum[i][j - 1] + board[i][j];
		}
	}	
	for (int i = 0; i < m; i++) {
		res += sum[i][m - 1];

	}
	for (int i = m-1; i < n; i++) {
		for (int j = m-1; j < n; j++) {
			int t = 0;
				for (int k = i-(m-1); k <= i; k++) {
					int nj = j - m;
					if (nj >= 0)
						t += sum[k][j] - sum[k][nj];
					else
						t += sum[k][j];
				}
			res = max(t, res);
		}
	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << '#' << i << " " << solve() << "\n";
	}
}