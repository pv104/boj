#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000002
#define ll long long
#define MOD (ll)1e9
ll dp[MAX], N;
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N; 
	dp[2] = 1;
	for (int i = 3; i <= N; i++) 
	dp[i] = ((((dp[i - 2] + dp[i - 1]) % MOD) * (i - 1)) % MOD);
	cout << dp[N];
}