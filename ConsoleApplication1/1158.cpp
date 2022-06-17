#include <bits/stdc++.h>
using namespace std;
int n, k;
void input()
{
	cin >> k >> n;
}
string solve()
{
	list<int> x;
	for (int i = 1; i <= k; i++)
		x.push_back(i);
	auto t = x.begin();
	string res = "<";
	vector<int> resultV;
	while (x.size() != 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (t == x.end())
			{
				t = x.begin();
				t++;
			}
			else
				t++;
		}
		t--;
		resultV.push_back(*t);
		t = x.erase(t);
	}

	for (int i = 0; i < resultV.size() - 1; i++)
		res += (to_string(resultV[i]) + ", ");
	res += to_string(resultV.back());
	res += ">";
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	cout << solve();
}