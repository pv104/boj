#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 1000005
stack <pair<int, int>> s;
int res[MAX];
int num[MAX];
int n;
void input()
{

	cin >> n;
	fill(res, res + MAX, -1);
	for (int i = 1; i <= n; i++)
		cin >> num[i];
}
void solve()
{
	for (int i = 1; i <= n; i++)
	{
		while (!s.empty() && s.top().second < num[i])
		{
			res[s.top().first] = num[i];
			s.pop();
		}
		s.push(make_pair(i,num[i]));
	}
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	solve();
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}