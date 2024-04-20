#include <iostream>
using namespace std;
#define I cin
int arr[100001];
int main() {int N, A, B, Q, K, T; I.tie(0); ios::sync_with_stdio(0); I >> N; while (--N) { I >> A >> B; ++arr[A]; ++arr[B];}I >> Q;while (Q--){I >> T >> K;if (T == 1 && arr[K] == 1) {cout << "no" << "\n";continue;}cout << "yes" << "\n";}}