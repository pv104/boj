	#include <iostream>
	#include <stack>
	#include <string>
	using namespace std;
	string str;
	void input()
	{
		cin >> str;
	}
	int solve()
	{
		stack <char> s;
		bool isSteel = false;
		int length = str.length();
		int res = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == '(')
			{
				isSteel = true;
				s.push(str[i]);
			}
			else // str[i] == ')'
			{
				if (isSteel)
				{
					s.pop();
					isSteel = false;
					res += s.size();
				}
				else
				{
					isSteel = false;
					res += 1;
					s.pop();
				}
			}
		}
		return res;
	}
	int main()
	{
		cin.tie(0); ios::sync_with_stdio(0);
		input();
		cout << solve();
	}