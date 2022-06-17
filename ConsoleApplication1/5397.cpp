#include <bits/stdc++.h>
using namespace std;
int t;
string solve()
{
	string str;
	list <char> x;
	auto cursor = x.begin();
	cin >> str;
	int len = str.length();
	string res = "";
	cursor = x.begin();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '<') // '<' 명령
		{
			if (cursor != x.begin())
				cursor--;
		}
		else if (str[i] == '>') // '>' 명령
		{
			if (cursor != x.end())
				cursor++;
		}
		else if (str[i] == '-') // '-' 명령
		{
			if (cursor != x.begin())
			{
				cursor--;
				cursor = x.erase(cursor);
			}
		}
		else // insert 명령
		{
			
			x.insert(cursor, str[i]);
		}
	}

	for (auto i : x)
		res += i;
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{ 
		cout << solve() << "\n";
	}
}