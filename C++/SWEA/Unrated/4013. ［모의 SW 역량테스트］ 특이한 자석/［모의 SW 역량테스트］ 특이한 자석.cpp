#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <deque>
#include <queue>
using namespace std;
int K, T;
deque<int> mag[5];
pair<int, int> rot[22];
int visited[5];
queue <pair<int, int>> q;
void init() {
	for (int i = 0; i < 5; i++)
		mag[i].clear();
	memset(rot, 0, sizeof(rot));
}
void input() {
	cin >> K;
	int x;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> x;
			mag[i].push_back(x);
		}
	}
	for (int i = 0; i < K; i++)
	{
		cin >> rot[i].first >> rot[i].second;

	}
}
void Check(int idx, int dir) {
	int nxt = 0;
	switch (idx)
	{
	case 1:
	{
		nxt = 2;
		if (visited[nxt] != 0 || (mag[1][2] == mag[2][6])) return;
		visited[nxt] = -dir;
			q.push({nxt,-dir});
		return;
	}
	case 2:
	{
		nxt = 1;
		if (visited[nxt] == 0 && (mag[1][2] != mag[2][6]))
		{
			visited[nxt] = -dir;
			q.push({nxt,-dir});
		}
		nxt = 3;
		if (visited[nxt] == 0 && (mag[2][2] != mag[3][6]))
		{
			visited[nxt] = -dir;
			q.push({nxt,-dir});
		}
		return;
	}
	case 3:
	{
		nxt = 2;
		if (visited[nxt] == 0 && (mag[2][2] != mag[3][6]))
		{
			visited[nxt] = -dir;
			q.push({nxt,-dir});
		}
		nxt = 4;
		if (visited[nxt] == 0 && (mag[3][2] != mag[4][6]))
		{
			visited[nxt] = -dir;
			q.push({nxt,-dir});
		}
		return;
	}
	case 4:
	{
		nxt = 3;
		if (visited[nxt] == 0 && (mag[3][2] != mag[4][6]))
		{
			visited[nxt] = -dir;
			q.push({nxt,-dir});
		}
		return;
	}
	default:
		break;
	}
	return;
}
void Rotate(int idx, int dir) {

	int b = mag[idx].back();
	int f = mag[idx].front();
	if (dir == 1) {
		mag[idx].pop_back();
		mag[idx].push_front(b);
	}
	else
	{
		mag[idx].pop_front();
		mag[idx].push_back(f);
	}
	return;
}
int solve() {

	int res = 0;

	for (int cnt = 0; cnt < K; cnt++)
	{

		int idx = rot[cnt].first;
		int dir = rot[cnt].second;
		q.push({ idx,dir });
		visited[idx] = dir;

		while (!q.empty()) {
			Check(q.front().first,q.front().second); q.pop();
		}

		Rotate(idx, dir);
		for (int i = 1; i < 5; i++) {
			if (idx == i) continue;
			if (visited[i] != 0) {
				Rotate(i, visited[i]);
			}
		}
		memset(visited, 0, sizeof(visited));
	}
	int mul = 1;

		for (int i = 1; i < 5; i++) {
			if (mag[i].front() == 1)
				res += mul;
			mul <<= 1;
		}

	return res;
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);

	cin >> T;
	for (int TC = 1; TC <= T; TC++)
	{
		init();
		input();
		cout << "#" << TC << " " << solve() << "\n";
	}
}