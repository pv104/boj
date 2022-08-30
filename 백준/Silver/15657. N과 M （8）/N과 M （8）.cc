#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int ori[10];
bool isused[10];
int n, m;
void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < k; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (k == 0 || (k > 0 && arr[k - 1] <= ori[i]))
		{
			arr[k] = ori[i];
			func(k + 1);
		}
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> ori[i];
	sort(ori, ori + n);
	func(0);
}