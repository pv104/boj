#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
#define SIZE 22
#define pii pair<int,int>
#define Y first
#define X second
#define INF 9
int N, M, res;
int board[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0, 1,0,-1 };
void moveBlock();
void rotateBlock();
void print();
int tboard[SIZE][SIZE];
typedef struct starter
{
	int y;
	int x;
	int cost;
	int cnt;
	int rainbowCnt;
}Starter;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}
Starter bfs(Starter current) {
	int y = current.y;
	int x = current.x;
	int cost = current.cost;
	int nrc = 0;
	queue <Starter> q;
	// y,x,cnt,rainbowCnt
	Starter s = { y,x,cost,0,0 };
	q.push(s);
	visited[y][x] = true;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N
				|| visited[ny][nx] || board[ny][nx] == -INF) continue;
			if (board[ny][nx] == 0 || board[ny][nx] == cur.cost) {
				if (board[ny][nx] == 0) nrc++;
				visited[ny][nx] = true;
				Starter t = { ny,nx,cur.cost,0,nrc };
				q.push({ ny,nx,cur.cost,0,nrc });
				if (board[ny][nx] > 0) {
					if (s.y > ny)
					{
						s = t;
						continue;
					}
					else if (s.y == ny)
					{
						if (s.x > nx)
						{
							s = t;
							continue;
						}
					}
				}

			}
		}
	}
	s.rainbowCnt = nrc;
	return s;
}
int calcul(Starter current) {
	int y = current.y;
	int x = current.x;
	int cost = current.cost;
	int cnt = 0;
	queue <Starter> q;
	q.push({ y,x,cost,0,0 });
	visited[y][x] = true;
	board[y][x] = -INF;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		cnt++;
		board[cur.y][cur.x] = -INF;
		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N
				|| visited[ny][nx] || board[ny][nx] == -INF) continue;
			if (board[ny][nx] == 0 || board[ny][nx] == cur.cost) {
				visited[ny][nx] = true;
				q.push({ ny,nx,cur.cost,0,0 });
			}
		}
	}
	return cnt * cnt;
}
int calc() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j])
				++cnt;
		}
	}
	return cnt;
}
int solve() {
	Starter s = {}, t = {};

	// 1. BFS -> 개수, 무지개개수,시작정점 체크
	while (true)
	{
		s = {};
		t = {};
		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N; j++) {
				if (board[i][j] < 1) continue;

				t = bfs({ i,j,board[i][j],0,0 });
				int cnt = calc();
				t.cnt = cnt;
				memset(visited, false, sizeof(visited));
				if (cnt < 2) continue;
				if (s.cnt <= t.cnt)
				{
					if (s.cnt < t.cnt)
					{
						s = t;
						continue;
					}
					if (s.rainbowCnt <= t.rainbowCnt)
					{
						if (s.rainbowCnt < t.rainbowCnt)
						{
							s = t;
							continue;
						}
						if (s.y <= t.y) {
							if (s.y < t.y) {
								s = t;
								continue;
							}
							if (s.x < t.x)
							{
								s = t;
								continue;
							}
						}
					}
				}
			}// j
		} // i

		// 2. 해당 그룹 BFS로 찾고, 지우고, 점수 더하기
		// 기준 정점을 시작점으로 하는 BFS
		if (s.cnt < 2) return res;
		int score = calcul(s);
		memset(visited, false, sizeof(visited));
		res += score;
		// 3. 가장 아래 블록에서 시작해서 위로 가면서 -1이 아닐때까지 칸수 세기
		// OOB가 되거나 종료됐을때 현재 블럭이 움직일 수 있는 경우 칸수 만큼 아래로 내리고, 해당 위치부터 시작하기
		moveBlock();
		// 4. i,j -> N-1-j행 i열로 보내기
		rotateBlock();

		// 5. 가장 아래 블록부터 잡고 OOB거나 -1일때까지 이동
		moveBlock();


	}
	return res;
}
// 3. 가장 아래 블록부터 잡고 OOB거나 -1일때까지 이동
void moveBlock() {
	for (int c = 0; c < N; c++) {
		queue <int> q = {};
		int r = N - 1;

		while (r >= 0) {
			// -INF인 경우 -> 빈 칸
			if (board[r][c] == -INF)
			{
				q.push(r);
			}
			// 블럭
			else if (board[r][c] >= 0)
			{
				if (!q.empty())
				{
					auto tr = q.front(); q.pop();
					swap(board[r][c], board[tr][c]);
					q.push(r);
				}
			}
			else if (board[r][c] == -1) {
				q = {};
			}
			--r;
		}
	}

}
void rotateBlock() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tboard[N - 1 - j][i] = board[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = tboard[i][j];
		}
	}
	memset(tboard, 0, sizeof(tboard));
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == -1)
				cout << 8 << ' ';
			else if (board[i][j] == -INF)
				cout << 7 << ' ';
			else
				cout << board[i][j] << ' ';
		}
		cout << "\n";
	}
}
int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	//FILE* stream;
	//freopen_s(&stream, "input.txt", "r", stdin);
	input(); cout << solve();
}