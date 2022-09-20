#include <iostream>
#include <algorithm>
using namespace std;
int arr[10], dat[10];
int n, m;
void Permutation(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		arr[k] = dat[i];
		Permutation(k + 1);
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> dat[i];
	sort(dat, dat + n);
	Permutation(0);
}