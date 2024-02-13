#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, z;
vector<char> op;
vector<int> ar;
int minRes = INT32_MAX;
int maxRes = INT32_MIN;
vector<int>np;
void input() {
	int t, y = 0;
	int x = 0;
	char ops[4] = { '+','-','*','/' };
	cin >> n;
	ar.resize(n);
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	for (int i = 0; i < 4; i++) {
		cin >> t;
		z += t;
		for (int j = 0; j < t; j++) {
			op.push_back(ops[x]);
		}
		++x;
	}
	for (int i = 0; i < op.size(); i++)
		np.push_back(i);

}
void solve() {
	do
	{
		int res = ar[0];
		for (int i = 1; i < n; i++) {

			char oper = op[np[i-1]];
			if (oper == '+') {
				res += ar[i];
			}
			else if (oper == '-') {
				res -= ar[i];
			}
			else if (oper == '*') {
				res *= ar[i];
			}
			else if (oper == '/') {
				if (res < 0) {
					res = -res;
					res = -(res / ar[i]);
				}
				else {
					res /= ar[i];
				}
			}
		}
		minRes = min(minRes, res);
		maxRes = max(maxRes, res);
	} while (next_permutation(np.begin(),np.end()));
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	solve();
	cout << maxRes << "\n" << minRes;
}