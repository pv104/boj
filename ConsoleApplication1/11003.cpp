#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;
#define MAX 11111111
#define INF 2147483647
int l, n;
deque <int> dq;
int Arr[MAX];
void input()

{
	int x;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) // 초기 세팅
	{
		cin >> x;
		dq.push_back(x);
	}
	fill(Arr, Arr + MAX, INF);
}
void solve()
{
	int cnt = 0;
	
	priority_queue <int,deque<int>,greater<int>> pq;

	for (int i = 1; i <= n; i++)
	{
		pq.push(dq.front());
		cout << pq.top() << ' ';
		dq.pop_front();
	}

}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	solve();
}