#include <bits/stdc++.h>
using namespace std;
stack <int> s;
void solve()
{
	vector <char> resV;
	vector <int> cmp;
	int n, t;
	string res = "";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		cmp.push_back(t);
	}
	int cnt = 0, n_cnt = 1;
	while (cnt != n)
	{
		if (s.empty() || (s.top() != cmp[cnt]))
		{
			resV.push_back('+');
			s.push(n_cnt++);
		
		}
		if(s.top() == cmp[cnt])
		{
			resV.push_back('-');
			s.pop();
			cnt++;
		}

		if (n_cnt > n && !(s.empty()) && (s.top() != cmp[cnt]))
		{
			cout << "NO";
			return;
		}
	}
	for(auto i : resV)
	{
		cout << i << "\n";
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}