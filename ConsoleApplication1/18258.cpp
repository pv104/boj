/*STL »ç¿ë*/
#include <iostream>
#include <queue>
using namespace std;
#define MAX 2000005
queue <int> q;
int head, tail;
void push(int x)
{
	q.push(x);
}
int empty()
{
	if (q.empty()) return 1;
	else return 0;
}
int pop()
{
	if (q.empty()) return -1;
	int t = q.front();
	q.pop();
	return t;
}
int size()
{
	return q.size();
}
int front()
{
	if (q.empty()) return -1;
	else return q.front();
}
int back()
{
	if (q.empty()) return -1;
	else return q.back();
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "pop")
			cout << pop() << "\n";
		else if (s == "size")
			cout << size() << "\n";
		else if (s == "empty")
			cout << empty() << "\n";
		else if (s == "front")
			cout << front() << "\n";
		else if (s == "back")
			cout << back() << "\n";
		else
		{
			cin >> x;
			push(x);
		}
	}
}