#include <bits/stdc++.h>
using namespace std;
#define MAX 500005
long long n;
stack <pair<long long,long long>> s;
long long height[MAX];
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> height[i];
}
long long solve()
{
	long long result = 0;
	for (int i = 0; i < n; i++)
	{

		long long cnt = 1;
		while ((!(s.empty())) && ((s.top().first <= height[i])))
		{

			if (s.top().first == height[i]) {
				cnt = s.top().second + 1;
				
			}
			if (s.top().second > 1)
			{
				result += s.top().second;
			}
			else
			result++;
			s.pop();
		}
		if (!s.empty()) result++;
		s.push(pair<long long, long long>(height[i], cnt));

	}
	return result;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	cout << solve();
}