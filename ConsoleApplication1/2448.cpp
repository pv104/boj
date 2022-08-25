#include <iostream>
#define MAX 7160
using namespace std;
char arr[MAX/2][MAX];
int n;
void star(int i,int j,int n)
{
	if (n == 3)
	{
		arr[i][j] = '*';
		arr[i + 1][j - 1] = '*';
		arr[i + 1][j + 1] = '*';
		for (int y = j - 2; y <= j + 2; y++)
			arr[i + 2][y] = '*';
		return;
	}
	star(i, j, n / 2);
	star(i + n / 2, j - n / 2, n / 2);
	star(i + n / 2, j + n / 2, n / 2);
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	star(0, n - 1, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 2 - 1; j++)
		{
			if (arr[i][j] == '*')
				cout << '*';
			else cout << ' ';
		}

		cout << "\n";
	}
}