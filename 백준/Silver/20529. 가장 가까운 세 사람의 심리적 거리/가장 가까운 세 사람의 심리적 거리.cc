#include <iostream>
#define INF 987654321
#define MAX 100002
using namespace std;
int t, n;
int arr[MAX][4];
int res = INF;
int solve()
{
	char ch;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> ch;
			if (ch == 'E' || ch == 'S' || ch == 'T' || ch == 'J')
				arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	if (n > 32)
		return 0; // 33개부터는 무조건 3개이상인 MBTI가 존재함
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int temp[3] = { 0, };
				for (int l = 0; l < 4; l++)
				{
					temp[0] += (arr[i][l] ^ arr[j][l]);
					temp[1] += (arr[j][l] ^ arr[k][l]);
					temp[2] += (arr[i][l] ^ arr[k][l]);
				}
				res = min(res, temp[0] + temp[1] + temp[2]);
			}
		}
	}
	return res;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;
	for (int cnt = 0; cnt < t; cnt++)
	{
		cout << solve() << "\n";
		res = INF;
	}
}