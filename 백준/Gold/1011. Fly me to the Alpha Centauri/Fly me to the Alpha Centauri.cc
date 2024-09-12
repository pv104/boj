#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define SIZE 18
#define MAX 6
#define INF 1987654321
#define ui unsigned int
#define fastio cin.tie(0); cin.sync_with_stdio(0)
ui X, Y, T;
void input() {
	cin >> X >> Y;
}
ui rec(ui l, ui r, ui d, ui c) {
	if (l >= r) return c << 1;
	if (r - l <= (d+1)) return (c << 1) + 1;
	
	return rec(l + d + 1, r - d - 1, d + 1, c + 1);
}
ui solve() {
	return rec(X, Y, 0, 0);
}
int main() {
fastio;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		input(); cout << solve() << "\n";
	}
}