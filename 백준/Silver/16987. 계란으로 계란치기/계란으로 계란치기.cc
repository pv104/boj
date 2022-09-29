#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10
#define S first
#define W second
int n, res;
vector <pair<int, int>> v;

void F(vector <pair<int,int>> t, int s)
{
	if (s == n)
	{
		int cnt = 0;
		for (auto i : t)
		{
			if (i.S <= 0)
				cnt++;
		}
		res = max(res, cnt);
		return;
	}
	vector <pair<int, int>> v2 = t;
	for (int i = 0; i < n; i++)
	{
		v2 = t;
		if (i == s) continue;
		if (t[i].S > 0 && t[s].S > 0)
		{
			t[i].S -= t[s].W;
			t[s].S -= t[i].W;
		}
		F(t, s + 1);
		t = v2;
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	int t,t2;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> t2;
		v.push_back({ t,t2 });
	}
	F(v, 0);
	cout << res;
}