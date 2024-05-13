#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;
#define SIZE 22
queue <int> q;
int N, X, A, B, C, D;
int board[SIZE][SIZE];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int fav[SIZE*SIZE][4];
struct student {
	int like;
	int empty;
	int r;
	int c;
};
struct cmp {
	bool operator() (const student& a, const student& b)
	{
		if (a.like < b.like)
		{
			return a.like < b.like;
		}
		else {
			if (a.like == b.like)
			{
				if (a.empty < b.empty)
				{
					return a.empty < b.empty;
				}
				else {
					if (a.empty == b.empty)
					{
						if (a.r < b.r)
						{
							return a.r > b.r;
						}
						else {
							if (a.r == b.r)
							{
								return a.c > b.c;
							}
							// a.r > b.r
							else {
								return a.r > b.r;
							}
						}
					}
					// a.empty > b.empty
					else {
						return a.empty < b.empty;
					}
				}
			}
			// a.like > b.like
			else {
				return a.like < b.like;
			}
		}
	}
};
priority_queue <student, vector<student>, cmp> pq;
void input() {
	cin >> N;
	int f = N * N;
	for (int i = 1; i <= f; i++)
	{
		cin >> X;
		q.push(X);
		for (int j = 0; j < 4; j++) {
			cin >> fav[X][j];
		}
	}
}
student findCnt(pair<int, int> cur, int num)
{
	int like = 0;
	int empty = 0;
	for (int dir = 0; dir < 4; dir++)
	{
		int ny = cur.first + dy[dir];
		int nx = cur.second + dx[dir];
		if (ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
		if (board[ny][nx] == 0)
		{
			empty++;
		}
		for (auto i : fav[num])
		{
			if (board[ny][nx] == i)
			{
				like++;
				break;
			}
		}
	}

	return { like,empty,cur.first,cur.second };
}
student findSpace(int num)
{

	pq = priority_queue<student, vector<student>, cmp>{};
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] == 0)
			{

				pq.push(findCnt({ i,j }, num));
			}
		}
	}
	return pq.top();
}
int calc()
{
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j] > 0)
			{
				int t = 1000;
				for (int dir = 0; dir < 4; dir++)
				{
					int ny = i + dy[dir];
					int nx = j + dx[dir];

					if (ny <= 0 || nx <= 0 || ny > N || nx > N)
					{
						t /= 10;
						continue;
					}
					bool flag = false;
					for (auto like : fav[board[i][j]])
					{
						if (like == board[ny][nx])
						{
							flag = true; break;
						}
					}
					if (flag) continue;
					t /= 10;
				}
				res += t;
			}
		}
	}
	return res;
}
int solve() {
	while (!q.empty()) {

		int cur = q.front(); q.pop();
		auto res = findSpace(cur);

		board[res.r][res.c] = cur;
	}

	return calc();
}
int main() {/*
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);*/
	cin.tie(0); cin.sync_with_stdio(0);
	input(); cout << solve();
}