#include <iostream>
using namespace std;
int arr[10];
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
	for (int i = 1; i <= n; i++)
	{
		if (!isused[i])
		{
			arr[k] = i;
			isused[i] = true;
			func(k + 1);
			isused[i] = false;
		}
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;
	func(0);
}