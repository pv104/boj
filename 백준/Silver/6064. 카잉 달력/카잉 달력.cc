#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int Euclid(int n, int m)
{
	int lcm = 0;
	int r1, r2, r=1;

	if (n > m)
	{
		r1 = n;
		r2 = m;
		while (r != 0)
		{
			r = r1 % r2;
			r1 = r2;
			r2 = r;
		}
	}
	else
	{
		r1 = m;
		r2 = n;
		while (r != 0)
		{
			r = r1 % r2;
			r1 = r2;
			r2 = r;
		}
	}
	return n*m/r1;
}
int solve(int m, int n, int x, int y)
{
	int cnt = x;
	int ty = x % n;
	if (ty == 0) ty += n;
	int lcm = Euclid(n, m);

	while (lcm >= cnt)
	{
		if (ty == y)
			return cnt;
		ty += m;
		cnt += m;
		if (ty > n)
			ty %= n;
		if (ty == 0) ty += n;
	}
	if (ty == y) return cnt;
	else 
	return -1;
	// cnt > LCM = -1
	// 

}
int main()
{
	ios::sync_with_stdio(0);
	int n, m, t, x, y, t1, t2;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> x >> y;
		cout << solve(m, n, x, y) << "\n";
	}

}