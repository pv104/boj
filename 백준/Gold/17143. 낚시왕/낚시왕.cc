#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#define MAX 102
using namespace std;
typedef struct shark {
	int r;
	int c;
	int s;
	int d;
	int z;
}Shark;

Shark board[MAX][MAX];
int R, C, M;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void input() {
	cin >> R >> C >> M;
	int r, c, s, d, z;
	for (int i = 0; i < M; i++)
	{
		cin >> r >> c >> s >> d >> z;
		if (d == 1)
			d = 0;
		else if (d == 3)
			d = 1;
		else if (d == 4)
			d = 3;
		board[r][c] = {r,c,s,d,z };
	}
}
Shark findShark(int c) {
	for (int i = 1; i <= R; i++) {
		if (board[i][c].z > 0) {
			return board[i][c];
		}
	}
	return {};
}
void moveShark() {
	Shark tboard[MAX][MAX];
	memset(tboard, 0, sizeof(tboard));
	
	// 상어가 있으면 상어를 이동시킴
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j].z != 0) {
				int dir = board[i][j].d;
				int size = board[i][j].z;
				int speed = board[i][j].s;
				// 상,하
				if (dir == 0 || dir == 2) {
					speed %= (R - 1) * 2;
					// 방향 바꾸기
					
				}
				else {
					speed %= (C - 1) * 2;
					// 방향 바꾸기
					
				}

				int nr = i;
				int nc = j;

				for (int i = 0; i < speed; i++)
				{
					nr += dy[dir];
					nc += dx[dir];
					if (nr <= 0 || nc <= 0 || nr > R || nc > C) {
						dir = ((dir + 2) % 4);
						nr += dy[dir];
						nr += dy[dir];
						nc += dx[dir];
						nc += dx[dir];

					}
				}

				if (tboard[nr][nc].z < size) {
					tboard[nr][nc] = { nr,nc,board[i][j].s,dir,size };
				}
				board[i][j] = {};
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			board[i][j] = tboard[i][j];
	}
}
void print() {
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++) {
			cout << board[i][j].z << ' ';
		}
		cout << "\n";
	}
}
int solve() {
	int res = 0;
	int c = 0;
	while (++c <= C) {

		auto cur = findShark(c);
		res += cur.z;
		board[cur.r][cur.c] = {};
		
		moveShark();
		//print();

	}
	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input(); cout << solve();
}