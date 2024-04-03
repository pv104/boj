#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
void solve() {
	priority_queue <int> maxH;
	priority_queue <int, vector<int>, greater<int>> minH;

	int M;
	cin >> M;
	int x;
	// 1. 일단 maxHeap에 넣기
	// 2. if(maxH.size - minH.size > abs(1) = 
	// maxH.top을 minH에 push하고 maxH을 pop
	cout << (M - 1) / 2 + 1 << "\n";
	int cnt = 0;

	for (int i = 1; i <= M; i++) {
		cin >> x;
		maxH.push(x);
		if (minH.size() == 0) {
			minH.push(maxH.top());
			maxH.pop();
		}
			while ((minH.size() > 0 && maxH.size() > 0) && minH.top() < maxH.top()) {
				int minValue = minH.top();
				int maxValue = maxH.top();
				minH.pop();
				minH.push(maxValue);
				maxH.pop();
				maxH.push(minValue);
			}
			if(abs((int)minH.size() - (int)maxH.size()) > 1) {
				while (minH.size() > maxH.size()) {
					maxH.push(minH.top());
					minH.pop();
				}
				while (minH.size() < maxH.size()) {
					minH.push(maxH.top());
					maxH.pop();
				}
			}
		if (i % 2 == 1)
		{
			int print = maxH.size() > minH.size() ? maxH.top() : minH.top();
			++cnt;
			cout << print << " ";
		}
		if (cnt == 10) {
			cnt = 0;
			cout << "\n";
		}

	}
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		solve();
		cout << "\n";

	}
}