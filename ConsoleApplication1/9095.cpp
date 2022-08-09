#include <iostream>
using namespace std;
#define MAX 13
int t, n;
int d[MAX];
int solve()
{
	cin >> n;
	if (d[n] != 0) return d[n];
	d[1] = 1, d[2] = 2, d[3] = 4;
	for (int i = 4; i <= n; i++)
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	return d[n];
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;
	for (int i = 0; i < t; i++)
		cout << solve() << "\n";
}