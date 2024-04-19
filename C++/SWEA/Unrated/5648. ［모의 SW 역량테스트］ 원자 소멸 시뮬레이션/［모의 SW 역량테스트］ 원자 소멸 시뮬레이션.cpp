#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <memory.h>
#include <set>
#define pii pair<int,int>
#define MAX 1002
// dir -> 0 상 1 하 2 좌 3 우
// 0 = 상, 
bool visited[MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
using namespace std;
int N, K, Y, X, DIR, T;

typedef struct atom {
	int x;
	int y;
	int dir;
	int k;
}Atom;
typedef struct res {
	int i;
	int j;
	int dist;
}Res;
typedef struct cmp {
	bool operator()(const Res&a, const Res&b) {
		if (a.dist == b.dist)
			return a.i > b.i;
		return a.dist > b.dist;
	}
}cmp;
vector <Atom> v;
priority_queue<Res, vector<Res>, cmp> pq;
set<int> sets;
void init() {
	pq = priority_queue<Res, vector<Res>, cmp>();
	v.clear();
	memset(visited, false, sizeof(visited));
}
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y >> DIR >> K;
		v.push_back({ X,Y,DIR,K });
	}

}
// 1. index번째 점에서 v 전체를 돌면서 만날 수 있는 정점간 걸리는 시간 계산하기
// 2. 시간이 짧은 순으로 우선순위큐에 push
// 3. 우선순위큐에서 pop하고 두 정점중 하나라도 방문했으면 continue
void Find(Atom cur, int curIndex) {

	int dist = 0;
	int cx = cur.x;
	int cy = cur.y;
	int cdir = cur.dir;
	int ck = cur.k;
	for (int nxtIdx = curIndex + 1; nxtIdx < v.size(); nxtIdx++) {
		auto i = v[nxtIdx];
		int nx = i.x;
		int ny = i.y;
		int ndir = i.dir;
		int nk = i.k;
		// 상하
		if (cdir == 0)
		{
			if ((ndir == 1) && (cx == nx) && (cy < ny)) {
				dist = abs(ny - cy);
				pq.push({ curIndex,nxtIdx,dist });
			}
			else if ((ndir == 2))
			{
				int xx = nx - cx;
				int yy = ny - cy;
				if (xx == yy && xx > 0) {
					dist = (xx + yy);
					pq.push({ curIndex,nxtIdx,dist });
				}
			}
			else if ((ndir == 3))
			{
				int xx = cx - nx;
				int yy = ny - cy;
				if (xx == yy && xx > 0) {
					dist = (xx + yy);
					pq.push({ curIndex,nxtIdx,dist });
				}
			}
		}
		else if (cdir == 1)
		{
			if ((ndir == 0) && (cx == nx) && (cy > ny))
			{
				dist = abs(ny - cy);
				pq.push({ curIndex,nxtIdx,dist });
			}
			else if ((ndir == 2))
			{
				int xx = nx - cx;
				int yy = cy - ny;
				if (xx == yy && xx > 0) {
					dist = (xx + yy);
					pq.push({ curIndex,nxtIdx,dist });
				}
			}
			else if ((ndir == 3))
			{
				int xx = cx - nx;
				int yy = cy - ny;
				if (xx == yy && xx > 0) {
					dist = (xx + yy);
					pq.push({ curIndex,nxtIdx,dist });
				}
			}
		}
		else if (cdir == 2) 
		{
			if ((ndir == 3) && (cy == ny) && (cx > nx))
			{
				dist = abs(nx - cx);
				pq.push({ curIndex,nxtIdx,dist });
			}
			else if ((ndir == 0))
			{
				int xx = cx - nx;
				int yy = cy - ny;
				if (xx == yy && xx > 0) {
					dist = (xx + yy);
					pq.push({ curIndex,nxtIdx,dist });
				}
			}
			else if ((ndir == 1))
			{
				int xx = cx - nx;
				int yy = ny - cy;
				if (xx == yy && xx > 0) {
					dist = (xx + yy);
					pq.push({ curIndex,nxtIdx,dist });
				}
			}
		}
		else if (cdir == 3) 
		{
			if ((ndir == 2) && (cy == ny) && (cx < nx))
			{
				dist = abs(nx - cx);
				pq.push({ curIndex,nxtIdx,dist });
			}
			else if ((ndir == 0))
			{
				int xx = nx - cx;
				int yy = cy - ny;
				if (xx == yy && xx > 0) {
					dist = (xx + yy);
					pq.push({ curIndex,nxtIdx,dist });
				}
			}
			else if ((ndir == 1))
			{
				int xx = nx - cx;
				int yy = ny - cy;
				if (xx == yy && xx > 0) {
					dist = (xx + yy);
					pq.push({ curIndex,nxtIdx,dist });
				}
			}
		}
	}
}
int solve() {
	// key = {x,y} value = {dir,k}
	int res = 0;
	// 이동하기
	for (int i = 0; i < v.size(); i++)
		Find(v[i], i);
	while (!pq.empty())
	{
		sets = set<int>();
		auto cur = pq.top(); pq.pop();
		int i = cur.i;
		int j = cur.j;
		int dist = cur.dist;
		if (visited[i] || visited[j]) continue;
		//visited[i] = visited[j] = true;
		sets.insert(i);
		sets.insert(j);
		while (!pq.empty() && (pq.top().dist == dist))
		{
			cur = pq.top(); pq.pop();
			i = cur.i;
			j = cur.j;
			if (visited[i] || visited[j]) continue;
				//visited[i] = visited[j] = true;
			sets.insert(i);
			sets.insert(j);
		}
		for (auto e : sets) {
			res += v[e].k;
			visited[e] = true;
		}
		//cout << " Res : " << res << "\n";

	}

	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		init();

		input();

		cout << "#" << TC << " " << solve() << "\n";

	}
}