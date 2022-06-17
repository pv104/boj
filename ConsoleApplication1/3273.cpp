#include <iostream>
using namespace std;
int x, n;
int num[100005], cnt[2000005];
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		cnt[num[i]]++;
	}
	cin >> x;
}
int solve()
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (x - num[i] < 0) continue;
		if (cnt[x - num[i]] == 1) res++;
	}
	if (res == 1) return res;
	else return res / 2;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	cout << solve();
}