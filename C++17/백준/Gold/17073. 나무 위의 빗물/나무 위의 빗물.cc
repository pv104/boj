#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 500002
#define Y first
#define P second
int N, U, V;
double W;
int tree[SIZE];
void input() {
	cin >> N >> W;
	for (int i = 1; i < N; i++) {
		cin >> U >> V;
		tree[U]++;
		tree[V]++;
	}
}
double solve() {
	double cnt = 0;
	for (int i = 2; i <= N; i++)
	{
		if (tree[i] == 1)
			cnt++;
	}
	return W / cnt;

}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cout << fixed;
	cout.precision(10);
	input(); cout << solve();
}