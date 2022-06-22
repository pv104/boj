#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define MAX 100002
int board[MAX]; // 1부터
int t, n;
stack <int> s;
bool vis[MAX];
queue <int> q;
void input()
{
	fill(board, board + MAX, 0);
	fill(vis, vis + MAX, false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	
}
int solve()
{
	for (int i = 1; i <= n; i++)
	{
		s.push(i);
		while (!s.empty())
		{
			int cur = s.top();
			s.pop();
			if (board[i] == -1) continue;

			if (vis[cur] == false) // 아직 방문하지 않은 경우:경로에 추가
			{
				vis[cur] = true;
				q.push(board[cur]);
				s.push(board[cur]);
			}
			else // 방문한 정점을 만나면: 추가된 경로 체크
			{
				while (!q.empty())
				{
					if (q.front() == board[cur]) // 다음 갈 정점과 큐의 맨 앞 원소가 같으면: 싸이클이 생성됨
												// 싸이클이 생성 된 그룹은 이미 한 팀으로 묶였으므로 -1 처리
					{							// 큐의 원소와 정점이 같지 않은 경우:싸이클이 아니므로 pop
						while (!q.empty())
						{
							board[q.front()] = -1;
							q.pop();
						}
						while (!s.empty())
						{
							s.pop();
						}
					}
					else
						q.pop();
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (board[i] != -1) cnt++;
	}
	return cnt;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;
	while (t--)
	{
		input();
		cout << solve() << "\n";
	}
}