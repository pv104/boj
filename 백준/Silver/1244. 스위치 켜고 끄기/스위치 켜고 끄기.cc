#include <iostream>
using namespace std;
#define MAX 101
int n, p;
int s[MAX];
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];

	}
	cin >> p;
	int sc, num;
	for (int cnt = 0; cnt < p; cnt++) {
		cin >> sc >> num;
		if (sc == 1) {
			for (int i = num; i <= n; i += num) {
				if (s[i] == 0) {
					s[i] = 1;
				}
				else s[i] = 0;
			}
		}
		else {
			if (s[num] == 0) {
				s[num] = 1;
			}
			else s[num] = 0;
			int nx = num;
			int ny = num;
			while (nx > 1 && ny < n) {
				nx--;
				ny++;
				if (s[nx] != s[ny]) break;
				if (s[nx] == 0) {
					s[nx] = s[ny] = 1;
				}
				else {
					s[nx] = s[ny] = 0;
				}

			}

		}

		
	}
	int m = n / 20;
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
			cout << s[i] << ' ';
		if (i % 20 == 0) {
			if (i == n) break;
			else cout << "\n";
		}
	}
	return 0;
}