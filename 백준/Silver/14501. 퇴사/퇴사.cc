#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 25
#define END first.first
#define START first.second
#define WEIGHT second
using namespace std;
int dp[MAX];
vector <pair<pair<int,int>,int>> v[MAX]; // <<종료,시작>,돈>
int n, t, p;
void input()
{
	cin >> n;
	v[0].push_back({ {0,0},0 });
	for (int i = 1; i <= n; i++)
	{
		v[i].push_back({ {0,0},0 });
		bool flag = false;
		cin >> t >> p;
		
		int ED = t + i - 1;
		
		v[ED].push_back({{ED,i},p});
	}
	for (int i=1; i<=n; i++)
	sort(v[i].begin(), v[i].end());
}
int solve()
{
	int res = 0;
	if(v[1].size() > 1)
	dp[1] = v[1][1].WEIGHT;
	for (int i = 1; i <= n; i++)
	{

		for (int j = 0; j < i; j++)
		{
			for (auto& k : v[i])
			{
				if (k.START <= j) continue;
				
					dp[i] = max(dp[i], dp[j] + k.WEIGHT);
				

			}
		}
		if (dp[i] == 0)
		{
			for (auto k : v[i])
				dp[i] = max(dp[i], k.WEIGHT);
		}
	}
	

	for (int i = 1; i <= n; i++)
		res = max(dp[i], res);
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();

	cout << solve();

	return 0;
}