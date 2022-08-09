#include <iostream>
using namespace std;
#define MAX 1000002
int d[MAX], n;
int solve()
{
	int t = 0;
	d[1] = 0;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
			d[i] = min(d[i - 1] + 1, d[i / 2] + 1);
		else
			d[i] = d[i - 1] + 1;
		if (i % 3 == 0)
			d[i] = min(d[i], d[i / 3] + 1);
		
	}
	return d[n];
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cout << solve();
}