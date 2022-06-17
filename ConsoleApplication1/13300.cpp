#include <iostream>
using namespace std;
int Student[2][7]; // [0][0],[1][0] ¾È¾¸
int N, K;
void input()
{
	int t1, t2;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> t1 >> t2;
		Student[t1][t2]++;
	}
}
int solve()
{
	int res = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			while (Student[i][j] > 0)
			{
				Student[i][j] -= K;
				res++;
			}
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	input();
	cout << solve();
}