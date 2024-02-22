#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 11;
const int MAXCOUNT = 10;
const int DIRS = 4;
#define X first
#define Y second
#define WALL #
#define SPACE .
#define O O
int n, m, result = MAX;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector <int> startX(4);
vector <int> startY(4);
vector <int> numbers;
char board[MAX][MAX];
typedef struct marble {
	int cx;
	int cy;
	char c;
	marble() {}
	marble(int a, int b,char c) {
		this->cx = a;
		this->cy = b;
		this->c = c;
	}
}marble;
marble R, B;
static int moves(int dir, vector<vector<char>> &tboard,int& moveCounts) {

	// tboard에 복사(push_back vs resize)
	queue <marble> qq;
	queue <marble> q;
	int cnt = 0;
	int flag = 0;
	int blueDist = 0;
	int redDist = 0;
	//int isFirst = 0; // 1 =  파랑먼저, 0 = 빨강먼저
	//int bluenx = B.cx + dx[dir];
	//int blueny = B.cy + dy[dir];
	//int rednx = R.cx + dx[dir];
	//int redny = R.cy + dy[dir];
	//	if (bluenx == rednx) // 같은 직선상에 있는 경우
	//	{
	//		qq.push({ bluenx,startY[dir],'.' });
	//	}
	//	else if (blueny == redny) {
	//		qq.push({ startX[dir],blueny ,'.' });
	//	}

	//	while (!qq.empty()) {
	//		auto cur = qq.front(); qq.pop();
	//		int cx = cur.cx;
	//		int cy = cur.cy;
	//		int nx = cx - dx[dir];
	//		int ny = cy - dy[dir];
	//		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
	//		if (tboard[nx][ny] == 'B') {
	//			isFirst = 1;
	//			break;
	//		}
	//		if (tboard[nx][ny] == 'R') break;
	//		qq.push({ nx,ny,'.'});
	//	}
	//	cout << " R.x: " << R.cx << " R.y: " << R.cy << " B.x:" <<B.cx << " B.y : " << B.cy << "\n";

		tboard[R.cx][R.cy] = '.';
		tboard[B.cx][B.cy] = '.';
		/*if (isFirst == 1) {
			q.push(B);
			while (!q.empty()) {

				auto cur = q.front(); q.pop();
				int cx = cur.cx;
				int cy = cur.cy;
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				char marbles = cur.c;
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (tboard[nx][ny] == '#') {

					tboard[cx][cy] = marbles;
					continue;
				}
				else if (tboard[nx][ny] == 'O') {
					if (marbles == 'R') {
						++flag;
						continue;
					}
					else if (marbles == 'B') {
						flag += 2;
						return flag;
					}
				}
				q.push({ nx,ny,marbles });
				++moveCounts;
			}
			q.push(R);
			while (!q.empty()) {

				auto cur = q.front(); q.pop();
				int cx = cur.cx;
				int cy = cur.cy;
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				char marbles = cur.c;
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (tboard[nx][ny] == '#' || tboard[nx][ny] == 'B') {

					if (tboard[cx][cy] == 'R' || tboard[cx][cy] == 'B')
					{
						tboard[cx - dx[dir]][cy - dy[dir]] = marbles;
					}
					else
						tboard[cx][cy] = marbles;
					continue;
				}
				else if (tboard[nx][ny] == 'O') {
					if (marbles == 'R') {
						++flag;
						continue;
					}
					else if (marbles == 'B') {
						flag += 2;
						return flag;
					}
				}
				q.push({ nx,ny,marbles });
				++moveCounts;
			}
		}*/
			q.push(R);
			while (true) {

				auto cur = q.front(); q.pop();
				int cx = cur.cx;
				int cy = cur.cy;
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
				char marbles = cur.c;
				if (tboard[nx][ny] == '#') {
					R.cx = cx;
					R.cy = cy;
					break;
				}
				else if (tboard[nx][ny] == 'O') {
					if (marbles == 'R') {
						++flag;
						break;
					}
				}
				q.push({ nx,ny,marbles });
				++redDist;
				++moveCounts;
			}
			while (!q.empty()) q.pop();
			q.push(B);
			while (true) {

				auto cur = q.front(); q.pop();
				int cx = cur.cx;
				int cy = cur.cy;
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				char marbles = cur.c;
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
				if (tboard[nx][ny] == '#') {
					B.cx = cx;
					B.cy = cy;
					break;
				}
				else if (tboard[nx][ny] == 'O') {
					if (marbles == 'B') {
						flag += 2;
						break;
					}
				}
				q.push({ nx,ny,marbles });
				++blueDist;
				++moveCounts;
			}
	if ((B.cx == R.cx && B.cy == R.cy) && (blueDist != 0 || redDist != 0)) {
		/*cout << "BD : " << blueDist << " RD : " << redDist << "\n";

		cout << " R.x: " << R.cx << " R.y: " << R.cy << " B.x:" << B.cx << " B.y : " << B.cy << "\n";*/
		if (blueDist < redDist) {
			R.cx -= dx[dir];
			R.cy -= dy[dir];
		}
		else if (redDist < blueDist){
			B.cx -= dx[dir];
			B.cy -= dy[dir];
		}
		/*cout << " R.x: " << R.cx << " R.y: " << R.cy << " B.x:" <<B.cx << " B.y : " << B.cy << "\n";*/
	}
	tboard[R.cx][R.cy] = 'R';
	tboard[B.cx][B.cy] = 'B';
	return flag;
}
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
}
/// <summary>
/// // cur = 현재 방향, cnt = 움직인 횟수
/// pmt가 한 번 수행되면 numbers의 값이 변경되고, 이는 1번 움직여야 함을 의미함
/// 
/// </summary>
void pmt(int cnt, int pre, vector<vector<char>> boards) {

	if (cnt >= MAXCOUNT) {
		return;
	}
	int res = 0;
	for (int i = 0; i < DIRS; i++) {


		if (pre > 0 &&( ((pre + 2) % 4) == i)) continue;
		// 방향이 반대거나, 직전에 이동한 방향이면 XX
		int moveCounts = 0;
		vector<vector<char>> tboard(n);
		for (int k = 0; k < n; k++) {
			tboard[k].resize(m);
			for (int l = 0; l < m; l++) {
				tboard[k][l] = boards[k][l];
				if (tboard[k][l] == 'R')
				{
					R = { k,l, 'R' };
				}
				else if (tboard[k][l] == 'B')
				{
					B = { k,l, 'B' };
				}
			}
		}
		
		// 1번 수행
		res = moves(i, boards, moveCounts);
		
		
		// 움직였는데 아무 구슬도 들어가지 않은 경우
		if(res < 1 && moveCounts > 0) 
		{
			pmt(cnt + 1, i, boards);
		}// 빨간 구슬만 들어간 경우
		else if (res == 1)
		{
			result = min(cnt + 1, result);
		}

		for (int k = 0; k < n; k++) {			
			for (int l = 0; l < m; l++) {
				boards[k][l] = tboard[k][l];
			}
		}

	}
}
int solve() {
	
	vector <vector<char>> tboard(n);
	for (int i = 0; i < n; i++) {
		tboard[i].resize(m);
		for (int j = 0; j < m; j++) {
			tboard[i][j] = board[i][j];
		}
	}
	pmt(0, -1, tboard);
	return result;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();

	solve();
	if (result == 11) cout << -1;
	else cout << result;
}