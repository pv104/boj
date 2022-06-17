#include <iostream>
#include <string>
using namespace std;
int cmp[10], ans[10];
int solve(int n, string& strn, int len)
{
	bool flag = true;
	int res = 0;
	for (int i = 0; i < len; i++)
	{
		ans[strn[i] - '0']++;
	}
	ans[6] += ans[9];
	while (true)
	{
		for (int i = 0; i < 9; i++)
		{
			if (cmp[i] < ans[i]) flag = false;
		}
		if (flag) return res;
		
		for (int i = 0; i < 9; i++)
		{
			if (i == 6) cmp[i]++;
			cmp[i]++;
		}
		res++;
		flag = true;
	}
	return 0;
}
int main()
{
	int n = 0, len = 0;
	string strn = "";
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin >> n;
	strn = to_string(n);
	len = strn.length();
	cout << solve(n, strn, len);
}