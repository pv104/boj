#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100002
int N, M, A, B, Q, K, T;
int arr[MAX];
void input() {
	cin >> N;
	--N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		++arr[A];
		++arr[B];
	}
	cin >> Q;
}
void solve() {

	for (int i = 0; i < Q; i++) {
		cin >> T >> K;
		if (T == 1) {
			if (arr[K] == 1) cout << "no" << "\n";
			else if (arr[K] > 1) cout << "yes" << "\n";
		}
		else
			cout << "yes" << "\n";
	}
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input(); solve();
}