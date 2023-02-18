#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int VMAX = 1002, EMAX = 100002;
typedef struct Edge
{
	int u, v, w;
	Edge() : Edge(-1, -1, 0) {}
	Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww) {}
	bool operator< (const Edge& O)const { return w < O.w; }
}Edge;
int p[VMAX], n, m;
Edge e[EMAX];
int find(int a) // 루트 찾기
{
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) // 합치기(union)
{
	a = find(a);
	b = find(b);
	if (a == b) return false; // a == b이면 이미 합쳐져있음
	p[b] = a; 
	return true;
}
int solve()
{
	fill(p, p + VMAX, -1);
	cin >> n >> m;
	int a,b,c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		e[i] = Edge(a - 1, b - 1, c);
		
	}
	int cnt = 0, res = 0;
	sort(e, e + m);
	for (int i=0; i<m; i++)
	{	if (merge(e[i].u, e[i].v)) // 합쳐졌으면
		{
			res += e[i].w;
			cnt++;
		}
	if (cnt == n - 1) return res;
	}
	return -1;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cout << solve();
	return 0;
}