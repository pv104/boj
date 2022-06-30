#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 200010
int n, k;
int board[MAX];
int dist[MAX];
bool vis[MAX];
queue <int> q;
vector <int> v;
void input()
{
	cin >> n >> k;
}
int solve()
{
	q.push(n);
	vis[n] = true;
	int res = 0;
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == k)
		{
			res = dist[cur]; break;
		}
		if (cur > 0 && !vis[cur - 1])
		{
			q.push(cur - 1);
			vis[cur - 1] = true;
			dist[cur - 1] = dist[cur] + 1;
		}
		if (cur < MAX && !vis[cur + 1])
		{
			q.push(cur + 1);
			vis[cur + 1] = true;
			dist[cur + 1] = dist[cur] + 1;

		}
		if ((cur < 100000) && !vis[cur * 2])
		{
			q.push(cur * 2);
			vis[cur * 2] = true;
			dist[cur * 2] = dist[cur] + 1;
		}
	}

	while (!q.empty()) q.pop();
	v.push_back(k);
	int t = res - 1;
	q.push(k);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == n) 
			
			break;
		if (dist[cur + 1] == t && vis[cur+1])
		{
			q.push(cur + 1);
			v.push_back(cur + 1);
		}
		else if (dist[cur - 1] == t && vis[cur-1])
		{
			q.push(cur - 1);
			v.push_back(cur - 1);
		}
		else 
		{
			q.push(cur / 2);
			v.push_back(cur / 2);
		}
		t--;
	}
	reverse(v.begin(), v.end());
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input(); cout << solve() << "\n";
	for (auto i : v)
		cout << i << ' ';
}