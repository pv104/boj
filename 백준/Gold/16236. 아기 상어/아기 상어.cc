#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int Fish[25][25];
int Check[25][25];
constexpr int INF = 1001;
int BabyShark;
int BabySharkX, BabySharkY, BabySharkeat;
typedef struct FishSize
{
	int Size;
	int x;
	int y;
	int cnt;
	void init(int s, int x, int y,int cnt)
	{
		Size = s;
		this->x = x;
		this->y = y;
		this->cnt = cnt;
	}
}FishSize;
vector <FishSize> ScanData;
void Clear(int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			Check[i][j] = 0;
	}

}
int BFS(int n)
{
	queue <FishSize> readyQueue;
	FishSize T = ScanData.back();
	ScanData.pop_back();
	
	int TargetX = T.x, TargetY = T.y, TargetSize = T.Size;
	int cnt = 0;
	FishSize T2;
	T2.init(BabyShark, BabySharkX, BabySharkY, 0);
	readyQueue.push(T2);
	Clear(n);
	while (!(readyQueue.empty()))
	{
		T = readyQueue.front();
		readyQueue.pop();
		cnt = T.cnt;
		if ((T.x == TargetX) && (T.y == TargetY))
		{
			Fish[T.x][T.y] = 0;
			BabySharkeat++;
			if (BabySharkeat == BabyShark)
			{
				BabyShark++;
				BabySharkeat = 0;
			}
			BabySharkX = TargetX;
			BabySharkY = TargetY;
			return cnt;
		}
		if ((T.y > 0) && (Check[T.x][T.y - 1] != -1) && (Fish[T.x][T.y - 1] <= BabyShark))
		{
			Check[T.x][T.y - 1] = -1;
			FishSize Temp;
			Temp.init(Fish[T.x][T.y - 1], T.x, T.y - 1, cnt + 1);
			readyQueue.push(Temp);
		}
		if ((T.y < n - 1) && (Check[T.x][T.y + 1] != -1) && (Fish[T.x][T.y + 1] <= BabyShark))
		{
			Check[T.x][T.y + 1] = -1;
			FishSize Temp;
			Temp.init(Fish[T.x][T.y + 1], T.x, T.y + 1, cnt + 1);
			readyQueue.push(Temp);
		}
		if ((T.x > 0) && (Check[T.x - 1][T.y] != -1) && (Fish[T.x - 1][T.y] <= BabyShark))
		{
			Check[T.x - 1][T.y] = -1;
			FishSize Temp;
			Temp.init(Fish[T.x - 1][T.y], T.x - 1, T.y, cnt + 1);
			readyQueue.push(Temp);
		}
		if ((T.x < n - 1) && (Check[T.x + 1][T.y] != -1) && (Fish[T.x + 1][T.y] <= BabyShark))
		{
			Check[T.x + 1][T.y] = -1;
			FishSize Temp;
			Temp.init(Fish[T.x + 1][T.y], T.x + 1, T.y, cnt + 1);
			readyQueue.push(Temp);
		}
	}
	return 0;
}
int BFS(int TargetSize, int TargetX, int TargetY, int n)
{
	queue <FishSize> readyQueue;
	FishSize T;
	int cnt = 0;
	T.init(BabyShark, BabySharkX, BabySharkY, 0);
	readyQueue.push(T);

	while (!(readyQueue.empty()))
	{
		T = readyQueue.front();
		readyQueue.pop();
		cnt = T.cnt;
		if ((T.x == TargetX) && (T.y == TargetY))
		{

			return cnt;
		}
		if ((T.y > 0) && (Check[T.x][T.y - 1] != -1) &&(Fish[T.x][T.y-1] <= BabyShark))
		{
			Check[T.x][T.y - 1] = -1;
			FishSize Temp;
			Temp.init(Fish[T.x][T.y - 1], T.x, T.y - 1, cnt + 1);
			readyQueue.push(Temp);
		}
		if ((T.y < n - 1) && (Check[T.x][T.y + 1] != -1) && (Fish[T.x][T.y+1] <= BabyShark))
		{
			Check[T.x][T.y + 1] = -1;
			FishSize Temp;
			Temp.init(Fish[T.x][T.y+1], T.x, T.y + 1, cnt + 1);
			readyQueue.push(Temp);
		}
		if ((T.x > 0) && (Check[T.x - 1][T.y] != -1) && (Fish[T.x-1][T.y] <= BabyShark))
		{
			Check[T.x - 1][T.y] = -1;
			FishSize Temp;
			Temp.init(Fish[T.x-1][T.y], T.x - 1, T.y, cnt + 1);
			readyQueue.push(Temp);
		}
		if ((T.x < n - 1) && (Check[T.x + 1][T.y] != -1) && (Fish[T.x+1][T.y] <= BabyShark))
		{
			Check[T.x + 1][T.y] = -1;
			FishSize Temp;
			Temp.init(Fish[T.x+1][T.y], T.x + 1, T.y, cnt + 1);
			readyQueue.push(Temp);
		}

	}
	return INF;

}
bool Scan(int n)
{
	FishSize T;
	int x = 0, y = 0, minSize = INF;
	int MinDist = INF, TempDist = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((Fish[i][j] != 0) && (Fish[i][j] < BabyShark))
			{
				TempDist = BFS(Fish[i][j],i, j, n);
				Clear(n);
				if (MinDist > TempDist)
				{
					x = i;
					y = j;
					minSize = Fish[i][j];
					MinDist = TempDist;
				}
				else if (MinDist == TempDist)
				{
					
						if (i < x)
						{
							x = i;
							y = j;
							minSize = Fish[i][j];
						}
					
					else if ((i == x) && (j < y))
					{
						x = i;
						y = j;
						minSize = Fish[i][j];
					}
				}
			}
		}
	}

	if (minSize == INF || MinDist == 0)
		return false;
	T.init(minSize, x, y, 0);
	ScanData.push_back(T);
	return true;
}
int solve(int n)
{
	int res = 0;
	int t = 0;
	while (Scan(n))
	{
	t = BFS(n);
	if (t == 0) return res;
	else res += t;
	Clear(n);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> Fish[i][j];
			if (Fish[i][j] == 9)
			{
				Fish[i][j] = 0;
				BabyShark = 2;
				BabySharkX = i;
				BabySharkY = j;
				BabySharkeat = 0;
			}
		}
	}

	cout << solve(n);
}