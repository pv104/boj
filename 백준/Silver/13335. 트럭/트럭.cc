#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1002
int n, w, l, res, comp, nowW;
int W[MAX], Loc[MAX];
void input()
{
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++)
		cin >> W[i];
}
int solve()
{
	for (int idx = 0; idx < n; idx++)
	{
			if (nowW + W[idx] <= l)
			{
				nowW += W[idx];
				Loc[idx] = 0;
				for (int i = comp; i <= idx; i++)
				{
					Loc[i]++;
					if (Loc[i] > w)
					{
						comp++;
						nowW -= W[i];
					}
				}
				res++;
			}
			else
			{
				while (nowW + W[idx] > l)
				{
					for (int i = comp; i < idx; i++)
					{
						Loc[i]++;
						if (Loc[i] > w)
						{
							comp++;
							nowW -= W[i];
						}
					}
					res++;
				}
				nowW += W[idx];
				Loc[idx] = 1;
			}
	}

	if(Loc[n-1] <= w)
		res += (w - Loc[n-1] + 1);
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}