#include <cstdio>

int N, L;
unsigned int I;

//N자리 중 L자리 비트만 1인 수의 개수
unsigned int dp[32][32];

unsigned int re_dp(int idx, int left) {
	if (left < 0)
		return 0;
	if (idx == N)
		return dp[idx][left] = 1;
	if (dp[idx][left] > 0)
		return dp[idx][left];

	unsigned int& ret = dp[idx][left];
	ret = re_dp(idx + 1, left) + re_dp(idx + 1, left - 1);
	return ret;
}

void re_constr(int idx, int left) {
	if (idx == N) {
		printf("\n");
		return;
	}
	if (I > dp[idx + 1][left]) {
		printf("1");
		I -= dp[idx + 1][left];
		left--;
	}
	else
		printf("0");

	return re_constr(idx + 1, left);
}

int main() {
	scanf("%d %d %ud", &N, &L, &I);

	re_dp(0, L);
	re_constr(0, L);
}