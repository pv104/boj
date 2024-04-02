#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#include <string>
using namespace std;
#define MAX 100002
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqLow;
priority_queue <int, vector<int>, greater<int>> lowSub;
priority_queue <pair<int, int>> pqHigh;
priority_queue <int> highSub;
int N, M, P, L;
int recommend(int x) {
	int number = 0;
	// 가장 어려운 문제가 여러개라면 가장 문제 번호가 큰 것을 출력
	// 난이도와 번호를 찾고 해당 난이도와 번호를 가진 pair가 sub에 없을 때 까지 while문 돌리기
	if (x == 1) {
		while (!pqHigh.empty()) {
			if (highSub.empty() || highSub.top() != pqHigh.top().second) { // 없으면
				return pqHigh.top().second;
			}
			else { // 있으면
				pqHigh.pop();
				highSub.pop();
			}
		}
	}
	else {
		while (!pqLow.empty()) {
			if (lowSub.empty() || lowSub.top() != pqLow.top().second) { // 없으면
				return pqLow.top().second;
			}
			else { // 있으면
				pqLow.pop();
				lowSub.pop();
			}
		}
	}
	return number;
}
void add(int p, int l) {
	pqHigh.push({ l,p });
	pqLow.push({ l,p });
}
// pqHigh가 비어있는 경우 = 
void solved(int p) {
	highSub.push(p);
	lowSub.push(p);
}
void input() {
	cin >> N;
	int p, l;

	for (int i = 0; i < N; i++) {
		cin >> p >> l;
		add(p, l);
	}
}
void solve() {
	cin >> M;
	string str;
	int p, l, x;
	for (int cnt = 0; cnt < M; cnt++) {
		cin >> str;

		if (str == "add") {
			cin >> p >> l;
			add(p, l);
		}
		else if (str == "recommend") {
			cin >> x;
			cout << recommend(x) << "\n";
		}
		else if (str == "solved") {
			cin >> p;
			solved(p);
		}
	}
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0); input(); solve();
}