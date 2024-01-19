#include <iostream>
#include <map>
using namespace std;
#define MAX 100005
int N, M;
int train[MAX];
map <int, int> mm;
void input() {
	cin >> N >> M;
}
int solve() {
	int n, j, x;
	for (int i = 0; i < M; i++) {
		cin >> n >> j;
		--j;
		if (n == 1) {
			cin >> x;
			train[j] |= (1 << --x);
		}
		else if (n == 2) {
			cin >> x;
			train[j] &= ~(1 << --x);
		}
		else if (n == 3) {
			train[j] <<= 1;
			for (int i = 20; i <= 31; i++) {
				train[j] &= ~(1 << i);
			}
		}
		else if (n == 4) {
			train[j] >>= 1;
		}
	}

	for (int i = 0; i < N; i++) {
		mm.insert({ train[i],i });
	}
	return mm.size();
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input(); cout << solve();
}