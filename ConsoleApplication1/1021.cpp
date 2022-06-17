#include <iostream>
#include <deque>
#include <queue>
using namespace std;
deque <int> dq;
queue <int> q;
int n, m;
void input()
{
	int x;
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		dq.push_back(i);
	for (int i = 1; i <= m; i++)
	{
		cin >> x;
		
		q.push(x);
	}
}
int solve()
{
	int res = 0, Lcnt = 0, Rcnt = 0, cnt = 0;
	while (!q.empty())
	{
		while (dq.front() == q.front())
		{
			dq.pop_front();
			q.pop();
			if (q.empty())
			{
				return res;
			}
		}

		Lcnt = 0, Rcnt = 0, cnt = 0;
		while (dq[Lcnt] != q.front())
			Lcnt++;
			while (true)
			{
				if (q.front() == dq[cnt--])
					break;
				Rcnt++;
				if (cnt < 0) cnt = dq.size() - 1;
			}
			if (Lcnt >= Rcnt)
			{
				int t = 0;
				for (int i = 0; i < Rcnt; i++)
				{
					t = dq.back();
					dq.pop_back();
					dq.push_front(t);
				}
				res += Rcnt;
			}
			else
			{
				int t = 0;
				for (int i = 0; i < Lcnt; i++)
				{
					t = dq.front();
					dq.pop_front();
					dq.push_back(t);
				}
				res += Lcnt;
			}

	}
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}