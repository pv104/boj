#include <iostream>
#include <queue>
using namespace std;
#define MAX 500002
queue <pair<int, int>> q, sub;
int odd[MAX], even[MAX], brother[MAX];
bool vis[MAX];
int n, k, ksec;
void input()
{
	cin >> n >> k;
}
int solve()
{
	q.push({ n,0 });
	sub.push({ k,0 });
	if (n == k)
	{
		if (n > 500000) return -1;
		return 0;
	}
	while (!q.empty() || !sub.empty())
	{
		if (k > 500000) return -1;

		if (ksec % 2 == 0 && even[k] != 0 && brother[k] != 0) // ���� �̵��� �ð��� ¦��
		{
			return brother[k];
		}
		else if (ksec % 2 == 1 && odd[k] != 0 && brother[k] != 0) // ���� �̵��� �ð��� Ȧ��
		{

			return brother[k];
		}
		
		int t = q.size(); 
		while (t--) // ���� ¦��/Ȧ���� ������
		{
			auto cur = q.front(); q.pop();
			int x, sec;
			x = cur.first; sec = cur.second;
			sec++; // ���⼭ 1 ���������ִ� ������ if������ ������ �����ϱ� ���ؼ�
					
			if (sec % 2 == 1) // ������ �������Ѿ� 1���϶� Ȧ��, 2���϶� ¦��... �迭�� ��

			{
				if (x > 0 && odd[x - 1] == 0)
				{
					odd[x - 1] = sec;
					q.push({ x - 1,sec });

				}
				if (x < 500000 && odd[x + 1] == 0)
				{
					odd[x + 1] = sec;
					q.push({ x + 1,sec });
				}
				if (x > 0 && x * 2 <= 500000 && odd[x * 2] == 0)
				{
					odd[x * 2] = sec;
					q.push({ x * 2,sec });
				}
			}
			else
			{
				if (x > 0 && even[x - 1] == 0)
				{
					even[x - 1] = sec;
					q.push({ x - 1,sec });

				}
				if (x < 500000 && even[x + 1] == 0)
				{
					even[x + 1] = sec;
					q.push({ x + 1,sec });
				}
				if (x > 0 && x * 2 <= 500000 && even[x * 2] == 0)
				{
					even[x * 2] = sec;
					q.push({ x * 2,sec });
				}
			}

		}

		t = sub.size();
		while (t--) // ���� x+sec�� ����
		{

			auto cur = sub.front(); sub.pop();
			int x, sec;
			x = cur.first; sec = cur.second;
			if (brother[x + ++sec] == 0)
			{
				brother[x + sec] = sec;
				sub.push({ x + sec,sec });
				k = x + sec;
				ksec = sec;
			}

		}



	}
	return -1;
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input(); cout << solve();
}