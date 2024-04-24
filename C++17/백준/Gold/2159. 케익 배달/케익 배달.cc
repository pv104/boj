#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
#define MAX 100002
#define Y first
#define X second
#define ll long long 
#define INF INT64_MAX
#define pii pair<ll,ll>
#define dist(y1,x1,y2,x2) abs(y1 - y2) + abs(x1 - x2)
ll N, dp[MAX][5], user[MAX][2], dists[5];
// 12시부터 시계방향으로 12,3,6,9,제자리
ll dy[5] = { -1,0,1,0,0 };
ll dx[5] = { 0,1,0,-1,0 };

void input() {
	cin >> N;
	cin >> user[0][1] >> user[0][0];
	for (ll i = 1; i <= N; i++)
		cin >> user[i][1] >> user[i][0];
	for (ll i = 0; i < MAX; i++)
		fill(dp[i], dp[i] + 5, INF);
}
// 현재 위치의 idx, 현재 좌표(y,x)
ll re_dp(ll idx, ll dir, pii cur) {
	if (idx == N)
	{

		return 0;
	}
	ll cy = cur.Y;
	ll cx = cur.X;

	if (dp[idx][dir] != INF) return dp[idx][dir];
	dp[idx][dir] = min(dp[idx][dir], re_dp(idx + 1, 4, { user[idx+1][0],user[idx+1][1] }) 
		+ dist(cy, cx, user[idx + 1][0], user[idx + 1][1]));
	for (ll ndir = 0; ndir < 4; ndir++)
	{
		ll ny = user[idx + 1][0] + dy[ndir];
		ll nx = user[idx + 1][1] + dx[ndir];
		if (ny < 0 || nx < 0 || ny >= 100000 || nx >= 100000) continue;
		dp[idx][dir] = min(dp[idx][dir], re_dp(idx + 1, ndir, { ny,nx }) + dist(cy, cx, ny, nx));
	}
	return dp[idx][dir];

}
ll solve() {
	ll res = INF;

	res = min(res, re_dp(0, 0, { user[0][0],user[0][1] }));

	return res;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	//FILE* stream;
	//freopen_s(&stream, "input.txt", "r", stdin);
	input(); cout << solve();
}