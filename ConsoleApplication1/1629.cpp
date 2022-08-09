#include <iostream>
using namespace std;
#define ll long long
ll x, y, z;
ll mul(ll a, ll b, ll c)
{
	if (b == 1)
		return a % c;
	ll tmp = mul(a, b / 2, c) % c;

	if (b % 2 == 0)
		return (tmp * tmp) % c;
	else return ((tmp * tmp)%c * a) % c;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> x >> y >> z;
	cout << mul(x, y, z);
}
