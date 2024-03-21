#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;
#define MAX 4002
string s1, s2;
int dp[MAX][MAX];
int len1, len2;
void input() {
	cin >> s1 >> s2;
	len1 = s1.length();
	len2 = s2.length();
	memset(dp, -1, sizeof(dp));
}
	// 긴 문자열의 끝에서부터 연속 몇개가 일치하는지 확인하기, 매번 s2를 돌아야 하니까 for(i=0,i<len2)
int re_dp(int idx1, int idx2) {
	if (idx1 >= len1 || idx2 >= len2) 
		return 0;
	if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
	int t = 0;
	if (s1[idx1] == s2[idx2]) {
		// 해당 문자를 추가하는 경우
		t = re_dp(idx1 + 1, idx2 + 1) + 1;
	}
		// 해당 문자를 추가하지 않는 경우(길이 초기화)
	
	return dp[idx1][idx2] = t;
}
int solve() {

	int res = 0;
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
		res = max(res, re_dp(i, j));
		}
	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0); input(); cout << solve();
}