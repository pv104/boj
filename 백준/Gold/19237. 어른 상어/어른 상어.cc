#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <map>
using namespace std;
#define SIZE 22
#define pii pair<int,int>
#define Y first
#define X second
#define INF 987
struct shark
{
	int num;
	int y;
	int x;
	int dir;
	int dirs[4][4];
};
int N, M, K;
pii board[SIZE][SIZE];
int visited[SIZE][SIZE];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0, 1,0,-1 };
const int cdirs[5] = { 0,0,2,3,1 };
queue <shark> q;
shark sharks[SIZE*SIZE];
bool OOB(int y, int x)
{
	return y < 0 || x < 0 || y >= N || x >= N;
}
void input() {
	
	cin >> N >> M >> K;
	int x;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> x;
			if (x == 0) continue;
			sharks[x] = {x,i,j,0,{} };
			board[i][j] = { x,K };
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> x;
		sharks[i].dir = cdirs[x];
	}
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cin >> x;
				sharks[i].dirs[cdirs[j]][k] = cdirs[x];
			}
		}
	}
	for (int i = 1; i <= M; i++)
	{
		q.push(sharks[i]);
	}
}
// 큐에 들어가있는 모든 상어에 대해 동시에 움직이기
void moveShark()
{

	for (int i = 0; i < SIZE; i++)
	{
		fill(visited[i], visited[i] + SIZE, INF);
	}
	int size = q.size();

	while (size-- > 0)
	{
		auto cur = q.front(); q.pop();
		int cn = cur.num;
		int cy = cur.y;
		int cx = cur.x;
		int cdir = cur.dir;
		int cnt = 0;
		int ndir = 0;

		// 빈칸 먼저 확인
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			if (OOB(ny,nx) || board[ny][nx].Y > 0) continue;
			++cnt;
			ndir = dir;
		}
		// 빈칸 1개
		if (cnt == 1)
		{
			int ny = cy + dy[ndir];
			int nx = cx + dx[ndir];
			if (visited[ny][nx] < cn) 
			{
				sharks[cn] = { -1, };
				continue;
			}
			cur.y = ny;
			cur.x = nx;
			cur.dir = ndir;
			q.push(cur);
			visited[ny][nx] = cn;
		}// 빈칸이 여러개
		else if (cnt > 1) {
			bool flag = false;
			for (int dir = 0; dir < 4; dir++)
			{
				int ndir = cur.dirs[cdir][dir];
				int ny = cy + dy[ndir];
				int nx = cx + dx[ndir];
				if (OOB(ny, nx) || board[ny][nx].Y > 0) continue;

				if (visited[ny][nx] < cn)
				{
					sharks[cn] = { -1, };
					break;
				}
				cur.y = ny;
				cur.x = nx;
				cur.dir = ndir;
				q.push(cur); flag = true;
				visited[ny][nx] = cn;
				break;
			}
		} // 빈칸이 없음
		else if (cnt == 0)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];
				if (OOB(ny, nx) || board[ny][nx].Y != cn) continue;
				++cnt;
				ndir = dir;
			}
			// 번호 같은 칸 1개
			if (cnt == 1)
			{
				int ny = cy + dy[ndir];
				int nx = cx + dx[ndir];
				cur.y = ny;
				cur.x = nx;
				cur.dir = ndir;
				q.push(cur);
			}// 번호 같은 칸이 여러개
			else if (cnt > 1) {
				bool flag = false;
				for (int dir = 0; dir < 4; dir++)
				{
					int ndir = cur.dirs[cdir][dir];
					int ny = cy + dy[ndir];
					int nx = cx + dx[ndir];
					if (OOB(ny, nx) || board[ny][nx].Y != cn) continue;

					if (visited[ny][nx] < cn)
					{
						sharks[cn] = { -1, };
						break;
					}
					cur.y = ny;
					cur.x = nx;
					cur.dir = ndir;
					q.push(cur); flag = true;
					visited[ny][nx] = cn;
					break;
				}
				//// 이럴수가 있나??
				//if (!flag) {
				//	sharks[cn] = { -1 };
				//}
			}
		}
		if(sharks[cur.num].num != -1)
		sharks[cur.num] = cur;
	}
}
void pushShark()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j].Y == 0) continue;
			int &num = board[i][j].Y;
			int &time = board[i][j].X;
			if (--time > 0) continue;
			num = 0;
			time = 0;
		}
	}
	for (int i = 1; i <= M; i++) {
		int y = sharks[i].y;
		int x = sharks[i].x;
		int num = sharks[i].num;
		if (num < 1) continue;
		
		board[y][x] = { num,K };
	}
}
void print() {
	cout << "보드 판 \n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << " {" << board[i][j].Y << ',' << board[i][j].X << "} ";
		}
		cout << "\n";
	}
	cout << "상어 \n";
	for (int i = 1; i <= M; i++)
	{
		if (sharks[i].num < 1) continue;
		cout << " n : " << sharks[i].num << " y : " << sharks[i].y << " x : " << sharks[i].x
			<< " dir : " << sharks[i].dir << "\n";
	}
}
int solve() {
	int cnt = 0;
	while (++cnt <= 1000)
	{

		// 1. 상어 움직이기
		moveShark();
		pushShark();
		// 2. 냄새 뿌리기
		//cout << " 시간 : " << cnt << "\n";
		//print();
		if (q.size() == 1) return cnt;

	}
	return -1;
}
int main() {
	/*FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);*/
	cin.tie(0); cin.sync_with_stdio(0);
	input(); cout << solve();
}