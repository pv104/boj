#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define INF -1

typedef struct Tree
{
	int Vertex;
	int Weight;
}Tree;
bool visited[MAX];
vector <Tree> Graph[MAX];
stack <Tree> DfsStack;
int MaxWeight, MaxVertex;
int DFS(int End, int Cost)
{
	Tree Input;
	while (!(DfsStack.empty()))
	{
		int Index = DfsStack.top().Vertex;
		int Weight = DfsStack.top().Weight;
		DfsStack.pop();
	
		for (int j = 0; j < Graph[Index].size(); j++)
		{
			if ((visited[Graph[Index][j].Vertex]))
				continue;
			visited[Graph[Index][j].Vertex] = true;
			Input.Vertex = Graph[Index][j].Vertex;
			Input.Weight = Graph[Index][j].Weight;
			DfsStack.push(Input);
			DFS(End, Cost + Graph[Index][j].Weight);
		}
		if (MaxWeight < Cost)
		{
			MaxVertex = Index;
			MaxWeight = Cost;
		}
		visited[Index] = false;
	}
	return 0;
}
int solve(int y,int z)
{
	for (int j = 0; j < Graph[z].size(); j++)
	{
		DfsStack.push(Graph[z][j]);
		visited[z] = true;
		visited[Graph[z][j].Vertex] = true;
		DFS(y, Graph[z][j].Weight);
		//fill_n(visited, MAX, false);
		visited[Graph[z][j].Vertex] = false;
	}
	return 0;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	int v, x, y, z, t;
	int Weight, Vertex;
	Tree Input;
	cin >> v;
	for (int i = 1; i <= v; i++)
	{
		cin >> t;
		while (true)
		{
			cin >> Vertex;
			if (Vertex == INF)
				break;
			cin >> Weight;
			Input.Vertex = Vertex;
			Input.Weight = Weight;
			Graph[t].push_back(Input);
		}
	}

	x = 1;
	solve(INF, x);

	y = MaxVertex;
	fill_n(visited, MAX, false);
	solve(INF, y);
	z = MaxVertex;
	fill_n(visited, MAX, false);
	solve(y, z);

	cout << MaxWeight;
}