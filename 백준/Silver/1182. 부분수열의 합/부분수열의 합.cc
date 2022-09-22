#include <iostream>
#include <vector>
#define MAX 22
using namespace std;
bool isused1[MAX], isused2[MAX], isused3[MAX];
int n, res, s;
int arr[MAX], dat[MAX];
void Combination(int cnt, int m,int start)
{
	if (cnt == m)
	{
		int t = 0;
		for (auto i : arr)
			t += i;
		if(t == s)
		res++;
		return;
	}
	for (int i = start; i < n; i++)
	{
		arr[cnt] = dat[i];
		Combination(cnt + 1, m, i + 1);
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> dat[i];
	for (int i = 1; i <= n; i++)
	{
		Combination(0,i,0);
	}
	cout << res;
}