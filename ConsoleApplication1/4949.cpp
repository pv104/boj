	#include <iostream>
	#include <stack>
	#include <string>
	using namespace std;

	string solve(string& str)
	{
		stack <char> s;
		int length = str.length();
		for (int i = 0; i < length; i++)
		{
			if (str[i] == '[' || str[i] == '(')
				s.push(str[i]);
			if (str[i] == ']' || str[i] == ')')
			{
				if (s.empty()) return "no";
				if (str[i] == ']' && s.top() == '(')
					return "no";
				else if (str[i] == ')' && s.top() == '[')
					return "no";
				else s.pop();
			}
		
		}
		if (s.empty()) return "yes";
		else return "no";
	}
	int main()
	{
		cin.tie(0); ios::sync_with_stdio(0);
		string str = "";
		while (true)
		{
			getline(cin, str);
			if (str == ".") return 0;
			cout << solve(str) << "\n";
		}
	}