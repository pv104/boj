#include <iostream>
#include <vector>
#define MAX 22
using namespace std;
bool isused1[MAX], isused2[MAX], isused3[MAX];
int n, res, s;
int arr[MAX], dat[MAX];
void Ps(int sum,int cnt)
{
	if (cnt == n)
	{
		if (sum == s)
			res++;
			return;
		
	}
		Ps(sum,cnt+1);
		Ps(sum+dat[cnt], cnt + 1);
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> dat[i];
	Ps(0,0);
	if (s == 0) res--;
	cout << res;
}