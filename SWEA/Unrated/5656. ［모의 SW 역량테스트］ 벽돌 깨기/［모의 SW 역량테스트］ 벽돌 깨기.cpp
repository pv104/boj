#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
#define HSIZE 17
#define WSIZE 14
#define pii pair<int,int>
#define Y first
#define X second
#define INF 987654321
int H, W, N, res;
int board[HSIZE][WSIZE];
bool visited[HSIZE][WSIZE];
int firsts[HSIZE];
typedef struct marble
{
	int y;
	int x;
	int cost;
}Marble;
void init() {
	memset(board, 0, sizeof(board));
	memset(firsts, 0, sizeof(firsts));
	memset(visited, false, sizeof(visited));
	res = INF;
}
void input() {
	cin >> N >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (board[j][i] > 0)
			{
				firsts[i] = j;
				break;
			}
		}
	}
}
int calc(vector<vector<int>> &v) {
	int t = 0;
	for (auto i : v)
		for (auto j : i)
		{
			if (j > 0) ++t;
		}
	return t;
}
void attack(vector<vector<int>>& v,pii start)
{
	queue<pii> q;
	queue<Marble> mq;
	memset(visited, false, sizeof(visited));
	/*mq의 y,x부터 
	  (y-d,x)~(y+d,x)
	  (y,x-d)~(y,x+d)까지 하나씩 지나가면서
	  확인하고, 1인경우 방문처리 / 2 이상이면 mq에 넣기
	*/
	mq.push({ start.Y,start.X,v[start.Y][start.X] });
	visited[start.Y][start.X] = true;
	while (!mq.empty()) {
		auto st = mq.front(); mq.pop();
		int y = st.y;
		int x = st.x;
		int d = st.cost-1;
		for (int i = y - d; i <= y + d; i++)
		{
			if (i < 0 || i >= H || visited[i][x]) continue;
			visited[i][x] = true;
			if (v[i][x] > 1)
				mq.push({ i,x, v[i][x] });
		}
		for (int j = x - d; j <= x + d; j++)
		{
			if (j < 0 || j >= W || visited[y][j]) continue;
			visited[y][j] = true;
			if (v[y][j] > 1)
				mq.push({ y,j, v[y][j] });
		}
	}

	// 구슬 깨짐
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (visited[i][j]) {
				v[i][j] = 0;
			}
		}
	}
	// 한 열씩 보면서 1 이상인 값을 큐에 넣고, 0부터 재배치
	for (int i = 0; i < W; i++) {
		int cnt = 0;
		int idx = H;
		for (int j = H - 1; j >= 0; j--) {
			if (v[j][i] < 1) continue;
			mq.push({ j,i,v[j][i] });
			v[j][i] = 0;
		}
		cnt = mq.size();
		for (int j = 0; j < cnt; j++)
		{
			auto cur = mq.front(); mq.pop();
			v[--idx][cur.x] = cur.cost;
		}

		firsts[i] = idx; 
	}
}
void rec(int cnt,vector<vector<int>> vv)
{
	//cout << " cnt : " << cnt << " t : " << calc(vv) << "\n";
	if (cnt == N) {

		int t = calc(vv);
		/*cout << " t : " << t << "\n";*/
		res = min(t, res);
		return;
	}
	auto v = vv;
	
	for (int i = 0; i < W; i++) {

		int j = firsts[i];
		if (j >= H) continue;
			if (v[j][i] > 0)
			{
				attack(v, { j,i });
				rec(cnt + 1, v);
				for (int r = 0; r < H; r++) {
					for (int c = 0; c < W; c++) {
						v[r][c] = vv[r][c];
					}
				}
				for (int i = 0; i < W; i++) {
					for (int j = 0; j < H; j++) {
						if (v[j][i] > 0)
						{
							firsts[i] = j;
							break;
						}
					}
				}
			}
		
	}
	int t = calc(vv);
	/*cout << " t : " << t << "\n";*/
	res = min(t, res);
	return;
	return;
}
int solve() {
	vector<vector<int>> v(H);
	for (int i = 0; i < H; i++)
		v[i].resize(W);
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			v[i][j] = board[i][j];
	rec(0, v);
	return res;
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		init();
		input();
		cout << "#" << tc << " " << solve() << "\n";
	}
}