#include <iostream>
#include <algorithm>
using namespace std;
int l, c;
char arr[16], dat[16];
void Combination(int cnt, int start)
{
	if (cnt == l)
	{
		int c1 = 0, c2 = 0;
		for (int i = 0; i < l; i++)
		{
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				c1++;
			else c2++;
		}
		if (c1 < 1 || c2 < 2) return;
		for (int i = 0; i < l; i++)
			cout << arr[i];
		cout << "\n";
		return;
	}
	for (int i = start; i < c; i++)
	{
		arr[cnt] = dat[i];
		Combination(cnt + 1, i + 1);
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> dat[i];
	sort(dat, dat + c);
	Combination(0, 0);
}