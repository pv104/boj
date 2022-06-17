#include <bits/stdc++.h>
using namespace std;
#define MAX 500005
typedef long long ll;
stack <pair<ll, ll>> s;
vector <pair<ll, ll>> TOP;
ll res[MAX];
ll N;
void input()
{
	ll t;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		TOP.push_back(pair<ll,ll>(t,i));
		
	}
}
void solve()
{
	int cnt = N;
	for (int i = N-1; i >= 0; i--)
	{
		while (!s.empty() && s.top().first <= TOP[i].first)
		{
			res[s.top().second] = i+1;
			s.pop();
		}
		s.push(TOP[i]);
	}
	while (!s.empty()) {
		res[s.top().second] = 0;
		s.pop();
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	solve();
	for (int i = 0; i < N; i++)
		cout << res[i] << ' ';
}