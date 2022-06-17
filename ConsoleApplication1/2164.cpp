#include <iostream>
#include <queue>
using namespace std;
queue <int> q;
int n;
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);
}
int solve()
{
	int x;
	while (true)
	{
		if (q.size() == 1) return q.front();
		q.pop();
		if (q.size() == 1)
			return q.front();
		x = q.front();
		q.pop();
		q.push(x);
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}