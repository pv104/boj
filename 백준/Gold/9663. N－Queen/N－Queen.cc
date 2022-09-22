#include <iostream>
#define MAX 50
using namespace std;
bool isused1[MAX], isused2[MAX], isused3[MAX];
int board[MAX][MAX];
int n, cnt;
void Nqueen(int cur)
{
	if (cur == n)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1]) continue;
		isused1[i] = isused2[cur + i] = isused3[cur - i + n - 1] = true;
		Nqueen(cur + 1); 
		isused1[i] = isused2[cur + i] = isused3[cur - i + n - 1] = false;

	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	Nqueen(0);
	cout << cnt;
}