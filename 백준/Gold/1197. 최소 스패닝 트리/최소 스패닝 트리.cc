#include <bits/stdc++.h>
using namespace std;
#define SIZE 10002
#define pii pair<int,int>
int p[SIZE];
int V, E, A, B, C;
struct edge
{
	int dist;
	int y;
	int x;
};
struct cmp
{
	bool operator()(const edge& a, const edge& b)
	{
		return a.dist > b.dist;
	}
};
priority_queue <edge,vector<edge>,cmp> q;
int findSet(int x)
{
	if (x == p[x]) return x;
	return p[x] = findSet(p[x]);
}
void makeSet(int x)
{
	p[x] = x;
}
bool merge(int a, int b)
{
	if (findSet(a) == findSet(b)) return false;
	p[findSet(b)] = findSet(a);
	return true;
}
void input() {
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;
		q.push({ C,A,B });
	}
	for (int i = 0; i < V; i++)
	{
		makeSet(i);
	}
}
int solve()
{
	int res = 0, cnt = 1;
	while (true)
	{
		if (cnt == V) return res;
		auto cur = q.top(); q.pop();
		int a = cur.y;
		int b = cur.x;
		int dist = cur.dist;
		if (merge(a, b))
		{
			res += dist;
			++cnt;
		}
	}
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	input(); cout << solve();
}