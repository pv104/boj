#include <iostream>
#include <vector>
using namespace std;
int n, l;
const int MAX = 102;
int board[MAX][MAX];
void input() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}
int isAble(vector<int> arr) {
	int size = arr.size();
	vector <bool> w(size);
	for (int i = 0; i < size-1; i++) {
		int diff = arr[i] - arr[i + 1];
		if (abs(diff) > 1) { // 불가능
			return 0;
		}
		if (diff == 1) { // i>i+1
			int cnt = 1;
			for (int j = i + 1; j < size - 1; j++) {
				if (arr[j] == arr[j + 1]) ++cnt;
				else break;
			}
			if (cnt >= l) {
				for (int j = i + 1; j < w.size() - 1 && j < i + 1 + l; j++) {
					if (w[j] == false)
						w[j] = true;
					else return 0;
				}
				i += cnt-1;
			}
			else return 0;
		}
		else if (diff == -1) { // i<i+1
			int cnt = 1;
			for (int j = i; j > 0; j--) {
				if (arr[j] == arr[j - 1]) ++cnt;
				else break;
			}
			if (cnt >= l) {
				for (int j = i; j > 0 && j > i - l; j--) {
					if (w[j] == false)
						w[j] = true;
					else return 0;
				}
			}
			else return 0;
		}
	}
	return 1;
	
}
int solve() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		vector<int> t(n);
		for (int j = 0; j < n; j++) 
			t[j] = board[i][j];

		int xx = isAble(t);
		res += xx;
		
	}
	for (int i = 0; i < n; i++) {

		vector<int> t(n);
		for (int j = 0; j < n; j++) {
			t[j] = board[j][i];
		}

		int xx = isAble(t);
		res += xx;
	}

	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();

}