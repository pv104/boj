#include <bits/stdc++.h>
using namespace std;
stack <int> Main;
vector <int> Building;
int N;
void input()
{
	cin >> N;
	int t;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		Building.push_back(t);
	}
}
long long int solve()
{
	long long cnt = 0;
	int t = 0;
	for (int i=0; i<N; i++)
	{
		
		while (!Main.empty() && Main.top() <= Building[i])
			Main.pop();

		Main.push(Building[i]);
		cnt += (Main.size() - 1);
		

	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	cout << solve();
}