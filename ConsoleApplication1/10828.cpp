#include <bits/stdc++.h>
using namespace std;
#define MX 1000001
//stack <int> s;
//int main()
//{
//	cin.tie(0);
//	ios::sync_with_stdio(0);
//	int n;
//	int in;
//	string str;
//	cin >> n;
//	while (n--)
//	{
//		cin >> str;
//		if (str == "pop")
//		{
//			if (s.empty())
//				cout << -1 << "\n";
//			else
//			{
//				cout << s.top() << "\n";
//				s.pop();
//			}
//		}
//		else if (str == "size")
//		{
//			cout << s.size() << "\n";
//		}
//		else if (str == "empty")
//		{
//			if(s.empty())
//				cout << 1 << "\n";
//			else cout << 0 << "\n";
//		}
//		else if (str == "top")
//		{
//			if (s.empty())
//				cout << -1 << "\n";
//			else cout << s.top() << "\n";
//		}
//		else
//		{
//			cin >> in;
//			s.push(in);
//		}
//	}
//}
int dat[MX];
int pos;
void push(int x)
{
	dat[pos++] = x;
}
int pop()
{
	if (pos <= 0) return -1;
	int temp = dat[--pos];
	return temp;
}
int size()
{
	return pos;
}
int empty()
{
	if (pos <= 0) return 1;
	else return 0;
}
int top()
{
	if (pos <= 0) return -1;
	else return dat[pos - 1];
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, in;
	string s;
	cin >> n;
	while (n--)
	{
		cin >> s;
		if (s == "pop")
			cout << pop() << "\n";
		else if (s == "empty")
			cout << empty() << "\n";
		else if (s == "top")
			cout << top() << "\n";
		else if (s == "size")
			cout << size() << "\n";
		else
		{
			cin >> in;
			push(in);
		}
	}
}