#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;
#define MAX 202
#define MIN -1
int arr[MAX], lis[MAX], n;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i]--;
	}

}

int solve() {
	for (int i = 0; i < n; i++) {
		lis[i] = 1;
		for (int j = 0; j <= i; j++) {
			if (arr[j] < arr[i])
				lis[i] = max(lis[i], lis[j] + 1);
		}
	}

	int res = MIN;
	for (int i = 0; i < n; i++)
		res = max(lis[i], res);

	return n - res;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0); input(); cout << solve();
}