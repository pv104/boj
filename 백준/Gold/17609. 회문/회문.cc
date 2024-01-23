#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 100003
int t;
string s;
int solve() {
	string s1, s2;
	int cnt = 0;
	int len = s.length();
	if (len % 2 == 1) {
		s1 = s.substr(0, len / 2 + 1);
		s2 = s.substr(len / 2, len / 2 + 1);
	}
	else {
		s1 = s.substr(0, len / 2 + 1);
		s2 = s.substr(len/2 - 1, len / 2 + 1);
	}
	reverse(s2.begin(), s2.end());
	if (s1 == s2) {
		return 0;
	}
	int i1 = 0, i2 = 0;
	int len2 = s2.length();
	for (; i2 < len2; ) {
		if (s1[i1] == s2[i2]) {
			i1++;
			i2++;
			cnt++;
		} else {
			i2++;
		}
	}
	int res = cnt;
	i1 = i2 = cnt = 0;
	for (; i1 < len2; ) {
		if (s1[i1] == s2[i2]) {
			i1++;
			i2++;
			cnt++;
		}
		else {
			i1++;
		}
	}
	res = max(cnt, res);
	if (res >= len / 2) return 1;
	else return 2;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		cout << solve() << "\n";
	}
}