#include <iostream>
using namespace std;
#define MAX 250002
bool isErased[MAX];
int dat[MAX];
// index 1
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> dat[i];
	}
	int erased = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dat[i] != i-erased) // 지우기
		{
			isErased[i] = true;
			erased++;
		}
	}
	cout << erased;
}