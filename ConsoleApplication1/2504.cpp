#include <iostream>
#include <stack>
#define minLp -1
#define minRp -2
#define maxLp -3
#define maxRp -4
using namespace std;
string str;
stack <int> s;
stack <int> temp;
void input()
{
	cin >> str;
}
int solve()
{
	int res = 0, t = 1;
	int length = str.length();

	for (int i = 0; i < length; i++)
	{

		if (str[i] == '(')
		{
			s.push(minLp);
		}
		if (str[i] == '[')
		{
			s.push(maxLp);
		}
		if (str[i] == ')')
		{
			if (s.empty() || s.top() == maxLp) return 0;
			
			t = s.top();
			s.pop();
			if (t < 0)
			{
				s.push(2);
			}
			else
			{
				while (!s.empty() && s.top() > 0)
				{
					t += s.top();
					s.pop();
				}
				if (s.empty() || s.top() == maxLp) return 0;
				s.pop();
				t *= 2;
				s.push(t);
			}

		}
		else if (str[i] == ']')
		{
			if (s.empty() || s.top() == minLp) return 0;


			t = s.top();
			
			s.pop();
			if (t < 0)
			{
				s.push(3);
			}
			else
			{
				while (!s.empty() && s.top() > 0)
				{
					t += s.top();
					s.pop();
				}
				if (s.empty() || s.top() == minLp) return 0;
				s.pop();
				t *= 3;
				s.push(t);
			}
		}
	}

	while (!s.empty() && s.top() > 0)
	{
		res += s.top();
		s.pop();
	}
	if (s.empty())
		return res;
	else return 0;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}