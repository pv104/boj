#include <iostream>
#include <string>
using namespace std;
string solve()
{
	string s, cmps;
	int cnt[26] = {0,}, cmp[26] = {0,};
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		cnt[s[i] - 'a']++;
	}
	cin >> cmps;
	len = cmps.length();
	for (int i = 0; i < len; i++)
		cmp[cmps[i] - 'a']++;
	bool flag = true;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] != cmp[i]) flag = false;
	}
	if (flag) return "Possible";
	else return "Impossible";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cout << solve() << "\n";
	}
}