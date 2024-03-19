#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 3
#define INF 987654321
int dp_min[MAX], dp_max[MAX], t_min[MAX], t_max[MAX], arr[MAX], n;
int delta[MAX] = { -1,0,1 };
void input() {
	cin >> n;
	for (int i = 0; i < MAX; i++) {
		t_min[i] = INF;
		t_max[i] = -1;
	}
}
pair<int,int> solve() {
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < MAX; j++)
			cin >> arr[j];
		for (int j = 0; j < MAX; j++)
		{
			for (int k = 0; k < MAX; k++) {
				int cur = j + delta[k];
				if (cur < 0 || cur >= MAX) continue;
				t_min[cur] = min(dp_min[j] + arr[cur],t_min[cur]);
				t_max[cur] = max(dp_max[j] + arr[cur],t_max[cur]);
			}
		}
		for (int j = 0; j < MAX; j++)
		{
			dp_min[j] = t_min[j];
			dp_max[j] = t_max[j];
			t_min[j] = INF;
			t_max[j] = -1;
		}
	}

	pair<int, int> res = { -1, INF };
	for (int i = 0; i < MAX; i++) {
		res.first = max(dp_max[i], res.first);
		res.second = min(dp_min[i],res.second);
	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0); input();
	pair<int, int> res = solve();
	cout << res.first << " " << res.second;
}