#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
constexpr int INF = INT_MAX;
constexpr int MAX = 1005;
constexpr int R = 0;
constexpr int G = 1;
constexpr int B = 2;
constexpr int RGBMAX = 3;
int mem[MAX][RGBMAX];
int RGB[MAX][RGBMAX];

int DP(int Color, int n)
{
	if (n <= 1)
	{
		return mem[n][Color];
	}
	if (mem[n][Color] != INF) return mem[n][Color];
	if (Color == R)
		mem[n][Color] = min(min(mem[n][Color], DP(G, n - 1) + RGB[n][Color]),DP(B,n - 1)+RGB[n][Color]);
	else if (Color == G)
		mem[n][Color] = min(min(mem[n][Color], DP(R, n - 1) + RGB[n][Color]),DP(B,n - 1)+RGB[n][Color]);
	else
		mem[n][Color] = min(min(mem[n][Color], DP(R, n - 1) + RGB[n][Color]), DP(G, n - 1) + RGB[n][Color]);
	return mem[n][Color];
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	int n, r, g, b, MIN = INF;
	cin >> n;
	for (int i=0; i<MAX; i++)
	fill_n(mem[i], RGBMAX, INF);

	for (int i = 1; i <= n; i++)
	{
		cin >> r >> g >> b;
		RGB[i][R] = r;
		RGB[i][G] = g;
		RGB[i][B] = b;
	}
	mem[1][R] = RGB[1][R];
	mem[1][G] = RGB[1][G];
	mem[1][B] = RGB[1][B];
	for (int i = 0; i < RGBMAX; i++)
	{
		DP(i, n);
	}
	cout << min(min(mem[n][R], mem[n][G]), mem[n][B]);
}