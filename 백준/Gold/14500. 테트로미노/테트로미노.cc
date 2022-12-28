#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;
int Arr[505][505];
constexpr int BlocksNum = 19;
vector <vector<pair<int, int>>> Blocks(BlocksNum, vector<pair<int, int>>(0, make_pair(0, 0)));
// 0~1 : 1, 2 : 2, 3~6 : 3, 7~10: 4, 11~14 : 5, 15~18 : 6
void InitBlock()
{
	Blocks[0].push_back({ 0, 0 });
	Blocks[0].push_back({ 0, 1 });
	Blocks[0].push_back({ 0, 2 });
	Blocks[0].push_back({ 0, 3 });

	Blocks[1].push_back({ 0,0 });
	Blocks[1].push_back({ 1,0 });
	Blocks[1].push_back({ 2,0 });
	Blocks[1].push_back({ 3,0 });
	// ~1
	Blocks[2].push_back({ 0,0 });
	Blocks[2].push_back({ 0,1 });
	Blocks[2].push_back({ 1,0 });
	Blocks[2].push_back({ 1,1 });
	 //~2
	Blocks[3].push_back({ 0,1 });
	Blocks[3].push_back({ 1,0 });
	Blocks[3].push_back({ 1,1 });
	Blocks[3].push_back({ 1,2 });

	Blocks[4].push_back({ 0,0 });
	Blocks[4].push_back({ 0,1 });
	Blocks[4].push_back({ 0,2 });
	Blocks[4].push_back({ 1,1 });

	Blocks[5].push_back({ 0,0 });
	Blocks[5].push_back({ 1,0 });
	Blocks[5].push_back({ 2,0 });
	Blocks[5].push_back({ 1,1 });

	Blocks[6].push_back({ 0,1 });
	Blocks[6].push_back({ 1,1 });
	Blocks[6].push_back({ 2,1 });
	Blocks[6].push_back({ 1,0 });
	// ~3
	Blocks[7].push_back({ 0,0 });
	Blocks[7].push_back({ 1,0 });
	Blocks[7].push_back({ 1,1 });
	Blocks[7].push_back({ 2,1 });

	Blocks[8].push_back({ 0,1 });
	Blocks[8].push_back({ 1,1 });
	Blocks[8].push_back({ 1,0 });
	Blocks[8].push_back({ 2,0 });

	Blocks[9].push_back({ 0,0 });
	Blocks[9].push_back({ 0,1 });
	Blocks[9].push_back({ 1,1 });
	Blocks[9].push_back({ 1,2 });

	Blocks[10].push_back({ 1,0 });
	Blocks[10].push_back({ 1,1 });
	Blocks[10].push_back({ 0,1 });
	Blocks[10].push_back({ 0,2 });
	// ~4
	Blocks[11].push_back({ 0,0 });
	Blocks[11].push_back({ 1,0 });
	Blocks[11].push_back({ 2,0 });
	Blocks[11].push_back({ 2,1 });

	Blocks[12].push_back({ 0,0 });
	Blocks[12].push_back({ 0,1 });
	Blocks[12].push_back({ 0,2 });
	Blocks[12].push_back({ 1,0 });

	Blocks[13].push_back({ 0,0 });
	Blocks[13].push_back({ 0,1 });
	Blocks[13].push_back({ 1,1 });
	Blocks[13].push_back({ 2,1 });

	Blocks[14].push_back({ 0,2 });
	Blocks[14].push_back({ 1,0 });
	Blocks[14].push_back({ 1,1 });
	Blocks[14].push_back({ 1,2 });
	// ~5
	Blocks[15].push_back({ 0,0 });
	Blocks[15].push_back({ 0,1 });
	Blocks[15].push_back({ 1,0 });
	Blocks[15].push_back({ 2,0 });

	Blocks[16].push_back({ 0,0 });
	Blocks[16].push_back({ 0,1 });
	Blocks[16].push_back({ 0,2 });
	Blocks[16].push_back({ 1,2 });

	Blocks[17].push_back({ 0,1 });
	Blocks[17].push_back({ 1,1 });
	Blocks[17].push_back({ 2,0 });
	Blocks[17].push_back({ 2,1 });

	Blocks[18].push_back({ 0,0 });
	Blocks[18].push_back({ 1,0 });
	Blocks[18].push_back({ 1,1 });
	Blocks[18].push_back({ 1,2 });
}
int solve(int n, int m)
{
	int max = INT_MIN, temp = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < BlocksNum; k++)
			{
				for(int l = 0; l < 4; l++)
				{
					if (((i + Blocks[k][l].first) > n - 1) || ((j + Blocks[k][l].second) > m - 1))
					{
						temp = 0; break;
					}
					temp += Arr[i+Blocks[k][l].first][j+Blocks[k][l].second];
				}

				if (max < temp) max = temp;
				temp = 0;
			}
		}
	}
	return max;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	InitBlock();
	vector <int> res;
	int n, m, max = 0;
	
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cin >> Arr[i][j];
		}
		cout << solve(n, m);
	
}