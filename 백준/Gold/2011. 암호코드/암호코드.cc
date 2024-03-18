#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;
#define MAX 5002
#define MOD 1000000
int n;
int arr[MAX], dp[MAX][3];
vector<int> v;
void input() {
	string str = "";
	cin >> str;
	n = str.length();
	for (int i = 0; i < n; i++) {
		arr[i] = str[i] - '0';
	}
	memset(dp, -1, sizeof(dp));
	--n;
}
int re_dp(int cur, int len) {

	if (cur > n) return 0;
	if (arr[cur] == 0) return 0;
	if (len == 2) {
		if (arr[cur] * 10 + arr[cur + 1] > 26) return 0;
	}
	if ((cur == n && len == 1) || (cur == n - 1 && len == 2))
	{
		return 1;
	}
	if (dp[cur][len] != -1) return dp[cur][len];
	int t = 0;
	if (len == 1) {
		t += re_dp(cur + 1, 1);
		t %= MOD;
		t += re_dp(cur + 1, 2);
		t %= MOD;
	}
	else {
		t += re_dp(cur + 2, 1);
		t %= MOD; 
		t +=re_dp(cur + 2, 2);
		t %= MOD;
	}
	return dp[cur][len] = t;
}
int solve() {
	int res = re_dp(0, 1);
	res %= MOD;
	res += re_dp(0, 2); 
	res %= MOD;

	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();

}