#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int cnt[26], cmp[26];
int solve()
{
	int res = 0;
	string s, cmps;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		cnt[s[i] - 'a']++;
	}
	cin >> cmps;
	len = cmps.length();
	for (int i = 0; i < len; i++)
	{
		cmp[cmps[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		res += abs(cnt[i] - cmp[i]);
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << solve();
}