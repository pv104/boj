#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MAX = 51;
int Parent[MAX];
vector <vector<int>> Partys;
int result[MAX];
int GetParent(int x)
{
	if (Parent[x] == x) return x;
	return GetParent(Parent[x]);
}
bool UnionParent(int a, int b)
{
	a = GetParent(a);
	b = GetParent(b);
	if (a == b) return false;
	if (a < b) Parent[b] = a;
	else Parent[a] = b;
	return true;
}
bool FindParent(int a,int b)
{
	a = GetParent(a);
	b = GetParent(b);
	if (a == b) return true;
	return false;
}
int Party(int n, int m,int Knows, vector <int> & KnowsNum)
{
	int Result = 0;
	for (int i = 0; i < KnowsNum.size(); i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < Partys[j].size(); k++)
			{
				if (KnowsNum[i] == Partys[j][k])
				{
					for (int l = 0; l < Partys[j].size(); l++)
					{
						if (find(KnowsNum.begin(), KnowsNum.end(), Partys[j][l]) == KnowsNum.end())
						{
							if (UnionParent(Parent[KnowsNum[i]], Partys[j][l]))
								KnowsNum.push_back(Partys[j][l]);
						}
					}
					k = Partys[j].size();
					
				}
			}
		}
	}
	bool flag = true;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < Partys[i].size(); j++)
			{
				for (int k = 0; k < KnowsNum.size(); k++)
				{
					if (Parent[KnowsNum[k]] == Parent[Partys[i][j]])
					{
						flag = false;
						break;
					}

				}
			}
			if (flag)
			Result++;
			flag = true;
		}
	
	return Result;

}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	int n, m, Knows, PartyPeoples, PartyNum,KnowsT;
	vector <int> KnowsNum;
	cin >> n >> m;
	cin >> Knows;
	vector<int> a;
	for (int i = 0; i < m; i++)
		Partys.push_back(a);

	for (int i = 0; i < MAX; i++)
		Parent[i] = i; // Union-Find init

	for (int i = 0; i < Knows; i++)
	{
		cin >> KnowsT;
		KnowsNum.push_back(KnowsT);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> PartyPeoples;
		
		for (int j = 0; j < PartyPeoples; j++)
		{
			cin >> PartyNum;
			Partys[i].push_back(PartyNum);
		}
	}

	cout << Party(n, m,Knows,KnowsNum);
}