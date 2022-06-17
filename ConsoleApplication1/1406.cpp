#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
char dat[MAX];
int pre[MAX], nxt[MAX];
int unused = 1, cursor = 1;
void L()
{
	if (pre[cursor] != -1) cursor = pre[cursor];
}
void D()
{
	if (nxt[cursor] != -1) cursor = nxt[cursor];
}
void P(char x)
{
	dat[unused] = x;
	pre[unused] = cursor;
	nxt[unused] = nxt[cursor];
	if (nxt[cursor] != -1)
		pre[nxt[cursor]] = unused;
	nxt[cursor] = unused;
	unused++;
}
void B()
{
	if (nxt[cursor] != -1)
		pre[nxt[cursor]] = pre[cursor];
	nxt[pre[cursor]] = nxt[cursor];
}
void input()
{
	pre[0] = -1, nxt[0] = -1;

	int len = 0;
	string str;
	cin >> str;
	len = str.length();
	for (int i = 1; i <= len; i++)
	{
		dat[i] = str[i-1];
		pre[i] = i - 1;
		nxt[i] = i + 1;
	}
	pre[1] = -1;
	nxt[len] = -1;
}
void solve()
{
	int t;
	char op,in;
	cin >> t;
	while (t--)
	{
		cin >> op;
		if (op == 'L')
			L();
		else if (op == 'D')
			D();
		else if (op == 'B')
			B();
		else
		{
			cin >> in;
			P(in);
		}
	}

	cursor = 1;
	string res = "";
	while (nxt[cursor] != -1)
	{
		cout << dat[cursor];
		D();

	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	solve();
}
/*stl·Î ±¸Çö
list <char> x;
list<char>::iterator t = x.end();
int n;
void input()
{
	int len = 0;
	string str;
	cin >> str;
	len = str.length();
	for (int i = 0; i < len; i++)
	{
		x.push_back(str[i]);
	}
}
string solve()
{
	string res = "";
	char op, in;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> op;
		if (op == 'L')
		{
			if (t != x.begin())
				t--;
		}
		else if (op == 'D')
		{
			if (t != x.end())
				t++;
		}
		else if (op == 'B')
		{
			if (t != x.begin())
			{
				t--;
				t = x.erase(t);
			}
		}
		else if (op == 'P')
		{

			cin >> in;
			x.insert(t, in);
			
		}
	}

	for (auto it : x)
		res += it;
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	cout << solve();
}*/