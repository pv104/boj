#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1002
int val[MAX], idx[MAX], dp[MAX];
vector <pair<int, int>> v[MAX];
int n;
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> val[i];
}
int solve()
{
	int lis = 0;
	v[0].push_back({ 0,0 });
	for (int idx = 1; idx <= n; idx++)
	{
		int tmin = 987654321;
		for (auto i : v[lis])
			tmin = min(i.second, tmin);
		if (tmin < val[idx]) // lis 만족
		{
			v[++lis].push_back({ idx,val[idx] });
		}
		else
		{
			int i = lis;
			bool flag = false;
			while ((i-- > 0) && !flag)
			{
				for (int j = 0; j < v[i].size(); j++)
				{
					if (v[i][j].second < val[idx])
					{
						flag = true;
						v[i+1].push_back({ idx,val[idx] });
						break;
					}
				}
			}
		}
	}

	return lis;

}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}