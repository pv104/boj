#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000003
#define val first
#define len second
int n, x;
int input[MAX];
vector<int> arr;
bool comp(const pair<int, int>& a, const pair <int, int>& b) {
	return a.val < b.val;
}
int solve() {
	cin >> n;
	int res = 1;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	arr.push_back(input[0]);
	for(int i=1; i<n; i++) {
		x = input[i];
		if (arr.back() < x) { // 더 크면 상관없음
			arr.push_back(x);
			++res;
		}
		else {
			auto index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
			arr[index] = x; // 아니면 변경
			
		}
	}
	return res;
	}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cout << solve();
}