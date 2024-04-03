#include <algorithm>
#include <memory.h>
#include <iostream>
using namespace std;
#define MAX 14
#define INF -987654321
int N, M;
int board[MAX], op[4];
int minValue, maxValue;
void init() {
	memset(board, 0, sizeof(board));
	memset(op, 0, sizeof(op));
	minValue = -INF, maxValue = INF;
}
void input() {
	cin >> N;
	M = N - 1; // OP 개수
	for (int i = 0; i < 4; i++)
		cin >> op[i];
	for (int i = 0; i < N; i++)
		cin >> board[i];
}
int cal(int a, int b,int curOp) {
	switch (curOp)
	{
	case 0: 
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	default:
		break;
	}
	return 0;
}
void re_dp(int idx, int val) {

	if (idx == M) {
		minValue = min(minValue, val);
		maxValue = max(maxValue, val);
		return;
	}
		for (int j = 0; j < 4; j++) {
			if (op[j] != 0) {
				op[j]--;
				re_dp(idx + 1, cal(val, board[idx + 1], j));
				op[j]++;
			}
		}
}
int solve() {

	re_dp(0, board[0]);
	int res = maxValue - minValue;

	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		init(); input(); 
		cout << "#" << TC << " " << solve() << "\n";
	}
}