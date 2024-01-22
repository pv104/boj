#include <iostream>
#include <string>
using namespace std;
#define MAX 26
int res[MAX];
char solve() {
	string s = "";
	getline(cin, s);
	for (auto i : s) {
		if (i != ' ')
			res[i - 'a']++;
	}
	int maxValue = 0;
	for (auto i : res) {
		maxValue = max(i, maxValue);
	}
	int cnt = 0;
	char rc;
	for (int i = 0; i < MAX; i++) {
		if (maxValue == res[i])
		{
			cnt++;
			rc = i + 'a';
		}
	}
	if (cnt > 1) rc = '?';
	return rc;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	string s;
	getline(cin, s);
	t = stoi(s);
	for (int i = 0; i < t; i++) {
		cout << solve() << "\n";
		fill(res, res + MAX, 0);
	}
}