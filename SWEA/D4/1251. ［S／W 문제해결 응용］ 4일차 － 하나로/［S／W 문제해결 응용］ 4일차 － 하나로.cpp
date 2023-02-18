#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;
#define ll long long
constexpr int VMAX = 1002, EMAX = 1000002;
constexpr long long int INF = LLONG_MAX;
typedef struct Edge
{
	ll u, v, w;
	Edge() : Edge(-1, -1, INF) {} // 생성자 1
	Edge(ll uu, ll vv, ll ww) { u = uu, v = vv, w = ww; } // 생성자 2
	bool operator <(Edge& O) { return w < O.w; }
}Edge; 
ll v;
ll p[VMAX], r[VMAX], c[VMAX];
double cost;
Edge e[EMAX];
int find(int a)
{
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false;
	p[b] = a;
	return true;
}
void init()
{
	cin >> v;
	fill(r, r + VMAX, 0);
	fill(c, c + VMAX, 0);
	fill(p, p + VMAX, -1);
	for (int i = 0; i < v; i++)
		cin >> r[i];
	for (int i = 0; i < v; i++)
		cin >> c[i];
	cin >> cost;
	int cnt = 0;
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			if (i == j) continue;
			e[cnt++] = Edge(i, j, ((abs(r[i] - r[j]) * abs(r[i] - r[j])) + ((abs(c[i] - c[j]) * abs(c[i] - c[j])))));

		}
	}

	sort(e, e + EMAX);
}
ll solve()
{

	ll res = 0;
	int cnt = 0;
	for (int i = 0; i < EMAX; i++)
	{
		if (merge(e[i].u, e[i].v))
		{
			res += e[i].w;
			cnt++;
		}
		if (cnt == v - 1)
		{
			
			return round(res * cost);
		}
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		init();
		cout << '#' << i << ' ' << solve() << "\n";
	}
	return 0;
}