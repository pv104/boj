#include <iostream>
#include <algorithm>
using namespace std;
int n;
#define MAX 3
#define INF 987654321
int dp_min[MAX], dp_max[MAX], t_min[MAX], t_max[MAX];
int arr[MAX];
int delta[MAX] = { -1,0,1 };
void input() {
	cin >> n;
	for (int j = 0; j < MAX; j++)
	{
		cin >> arr[j];
		dp_min[j] = dp_max[j] = arr[j];
		t_min[j] = INF;
		t_max[j] = -1;
	}
}
pair<int,int> solve() {
	for (int i = 1; i < n; i++) {

		for (int j = 0; j < MAX; j++)
			cin >> arr[j];
		for (int j = 0; j < MAX; j++)
		{
			int minValue = INF;
			int maxValue = -1;
			int nxt = 0;
			int nxt_min = 0;

			// j번째 dp값과 arr[cur]를 비교해서 가장 큰 값으로 이동하기
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