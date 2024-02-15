//#include <iostream>
//#include <queue>
//#define W first.first
//#define X first.second
//#define Y second
//using namespace std;
//const int MAX = 1003;
//const int INF = 987654321;
//int n, m, x;
//vector <vector<pair<int,int>>> board;
//queue <pair<pair<int,int>,int>> q;
//int startCost[MAX], endCost[MAX];
//void input() {
//	cin >> n >> m >> x;
//	int r, c, w;
//	board.resize(n);
//	for (int i = 0; i < n; i++) {
//		cin >> r >> c >> w;
//		board[r].push_back({ w,c }); // r->c에 w
//	}
//}
//int solve() {
//	int res = 0;
//	fill(startCost, startCost + MAX, INF);
//	fill(endCost, endCost + MAX, INF);
//	startCost[1] = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (board[i].W < INF) {
//
//			}
//		}
//	}
//}
//int main() {
//	cin.tie(0); ios::sync_with_stdio(0);
//}


#include <iostream>
#include <vector>
#include <stack>
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
			else if (i == 0 && l == 1)
				w[i] = true;
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