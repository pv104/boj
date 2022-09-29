#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10
#define S first
#define W second
int n, res;
vector <pair<int, int>> v;

void F(int s)
{
	if (s == n)
	{
		int cnt = 0;
		for (auto i : v)
		{
			if (i.S <= 0)
				cnt++;
		}
		res = max(res, cnt);
		return;
	}
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (i == s) continue;
		if (v[i].S <= 0 || v[s].S <= 0) continue;

		flag = true;
		v[i].S -= v[s].W;
		v[s].S -= v[i].W;
		F(s + 1);
		v[i].S += v[s].W;
		v[s].S += v[i].W;
	}
	if (!flag) F(s + 1);
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	int t, t2;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> t2;
		v.push_back({ t,t2 });
	}
	F(0);
	cout << res;
}