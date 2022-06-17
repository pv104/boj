#include <bits/stdc++.h>
using namespace std;
#define MAX 1005
#define EDGEMAX 10005
#define INF 987654321
bool Visited[MAX];
int Dist[MAX];
int cnt;
vector <pair<int, int>> adj[MAX];
void init(int x)
{
	fill(Dist, Dist + MAX, INF);
	Dist[x] = 0;
}
int dijkstra(int n,int x,vector<int>& result)
{
	init(x);

	while (true)
	{ 
		int index = -1;
		for (int i = 1; i <= n; i++)
		{

			if (Visited[i]) {
				continue;
			}
			
			if (index == -1)
			{
				index = i;
			}
			else if (Dist[i] < Dist[index])
				index = i;
		}
		if (index == -1 || Dist[index] == INF) break;
			for (auto it = adj[index].begin(); it != adj[index].end(); it++)
			{
				if (Dist[it->first] == INF)
				{
					Dist[it->first] = Dist[index] + it->second;
				}
				else if	((Dist[index] + it->second) < Dist[it->first])
				{
					Dist[it->first] = Dist[index] + it->second;

				}
			}

			int min = INF, Vertex = x;

			for (int j = 1; j <= n; j++)
			{
				if (min > Dist[j] && (!Visited[j])) {
					min = Dist[j];
					Vertex = j;
				}
			}
			Visited[Vertex] = 1;

	}
	int max = 0, Vertex = 1;
	for (int i = 1; i <= n; i++)
	{
		max = (max < Dist[i]) ? Dist[i] : max;
		Vertex = i;
	}
	for (int i = 1; i <= n; i++)
	{
		if (max == Dist[i])
			result.push_back(i);
	}
	return max;
}
int main()
{
	ios::sync_with_stdio(0);
	int n, m, x, t, res2 = 0, max = 0, result = 0;
	vector <int> res1, res3;
	cin >> n >> m >> x;
	pair <int, int> a;
	for (int i = 1; i <= m; i++)
	{
		cin >> t >> a.first >> a.second;
		adj[t].push_back(a);
		
	}

	max = dijkstra(n,x,res1);
	fill(Visited, Visited + MAX, false);
	fill(Dist, Dist + MAX, INF);
	for (int i = 0; i < res1.size(); i++)
	{
		res2 = res1.back();
		res1.pop_back();
		dijkstra(n, res2, res3);

		result = ((result < max + Dist[x])) ? max + Dist[x] : result;

	}

	cout << result;
}