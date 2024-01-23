
#include <iostream>
using namespace std;
#define ll long long int
#define MAX 100003
ll n, m, i, j;
ll s[MAX];
ll arr[MAX];
void input() {
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
		cin >> arr[i];
	for (ll i = 1; i <= n; i++)
		s[i] = s[i - 1] + arr[i];
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	for (int cnt = 0; cnt < m; cnt++) {
		cin >> i >> j;
		cout << s[j] - s[i - 1] << "\n";
	}
}