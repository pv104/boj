#include <iostream>
#include <queue>
using namespace std;
#define MAX 500002
queue <pair<int,int>> q, sub;
int odd[MAX],even[MAX], brother[MAX];
bool vis[MAX];
int n, k, ksec;
void input()
{
	cin >> n >> k;
}
int solve()
{
	q.push({ n,0 });
	sub.push({ k,0 });
	if (n == k)
	{
		if (n > 500000) return -1;
		return 0;
	}
	while (!q.empty() || !sub.empty())
	{
		if (k > 500000) return -1;

		if (ksec % 2 == 0 && even[k] != 0 && brother[k] != 0)
		{

			return brother[k];
		}
		else if (ksec % 2 == 1 && odd[k] != 0 && brother[k] != 0)
		{

			return brother[k];
		}
		int t = sub.size();
		while (t--)
		{

			auto cur = sub.front(); sub.pop();
			int x, sec;
			x = cur.first; sec = cur.second;
			if (brother[x + ++sec] == 0)
			{
				brother[x + sec] = sec;
				sub.push({ x + sec,sec });
				k = x + sec;
				ksec = sec;
			}

		}
		t = q.size();
		while (t--)
		{
			auto cur = q.front(); q.pop();
			int x, sec;
			x = cur.first; sec = cur.second;
			
			if (sec % 2 == 0)

			{
				if (x > 0 && odd[x - 1] == 0)
				{
					odd[x - 1] = sec + 1;
					q.push({ x - 1,sec + 1 });

				}
				if (x < 500000 && odd[x + 1] == 0)
				{
					odd[x + 1] = sec + 1;
					q.push({ x + 1,sec + 1 });
				}
				if (x > 0 && x * 2 <= 500000 && odd[x * 2] == 0)
				{
					odd[x * 2] = sec + 1;
					q.push({ x * 2,sec + 1 });
				}
			}
			else
			{
				if (x > 0 && even[x - 1] == 0)
				{
					even[x - 1] = sec + 1;
					q.push({ x - 1,sec + 1 });

				}
				if (x < 500000 && even[x + 1] == 0)
				{
					even[x + 1] = sec + 1;
					q.push({ x + 1,sec + 1 });
				}
				if (x > 0 && x * 2 <= 500000 && even[x * 2] == 0)
				{
					even[x * 2] = sec + 1;
					q.push({ x * 2,sec + 1 });
				}
			}

		}

		


		
	}
	return -1;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input(); cout << solve();
}