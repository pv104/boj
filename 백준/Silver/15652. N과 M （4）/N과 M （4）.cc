#include <iostream>
using namespace std;
int arr[10];
int n, m;
void DupliCombination(int k,int start)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return;
	}
	for (int i = start; i <= n; i++)
	{
		arr[k] = i;
		DupliCombination(k + 1, i);
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;

	DupliCombination(0,1);
}