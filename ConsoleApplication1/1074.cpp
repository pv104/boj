#include <iostream>
using namespace std;
int Z(int n, int r, int c)
{
	if (n == 0)return 0;
	int half = 1 << (n - 1);
	
	if (r < half && c < half)
		return Z(n - 1, r, c);
	else if (r < half && c >= half)
		return half * half + Z(n - 1, r, c - half);
	else if (r >= half && c < half)
		return 2 * half * half + Z(n - 1, r - half, c);
	else
		return 3 * half * half + Z(n - 1, r - half, c - half);
	
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	int n, r, c;
	cin >> n >> r >> c;
	cout << Z(n, r, c);
}