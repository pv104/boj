#include <iostream>
using namespace std;
#define MAX 1003
int lcs[MAX][MAX];
string s1, s2;

int solve() {
	int res = 0;
	cin >> s1 >> s2;
	if (s1.length() < s2.length()) {
		swap(s1, s2);
	}
	s1 = " " + s1;
	s2 = " " + s2;
	int l1 = s1.length(), l2 = s2.length();
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			if ((s1[i] == s2[j]) && (isalpha(s1[i]) && isalpha(s2[j]))) {
				lcs[i][j] = max(lcs[i - 1][j - 1] + 1, max(lcs[i - 1][j], lcs[i][j - 1]));
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}
	return res = lcs[l1][l2];

}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cout << solve();
}