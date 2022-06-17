#include <bits/stdc++.h>
using namespace std;
stack <int> s;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int k, n;
	long long int res = 0;
	cin >> k;
	while (k--)
	{
		cin >> n;
		if (n == 0)
			s.pop();
		else
			s.push(n);
	}
	while (!(s.empty()))
	{
		res += s.top();
		s.pop();
	}
	cout << res;
}