#include <bits/stdc++.h>
using namespace std;
#define MAX 2001
int Ten[5][5][5];
int HexToBin[16][4] =
{
	{0,0,0,0},
	{0,0,0,1},
	{0,0,1,0},
	{0,0,1,1},
	{0,1,0,0},
	{0,1,0,1},
	{0,1,1,0},
	{0,1,1,1},
	{1,0,0,0},
	{1,0,0,1},
	{1,0,1,0},
	{1,0,1,1},
	{1,1,0,0},
	{1,1,0,1},
	{1,1,1,0},
	{1,1,1,1}
};
int Code[MAX][MAX];
int Answer;
int N, M;
void SettingCode()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				Ten[i][j][k] = -1;
	Ten[2][1][1] = 0;
	Ten[2][2][1] = 1;
	Ten[1][2][2] = 2;
	Ten[4][1][1] = 3;
	Ten[1][3][2] = 4;
	Ten[2][3][1] = 5;
	Ten[1][1][4] = 6;
	Ten[3][1][2] = 7;
	Ten[2][1][3] = 8;
	Ten[1][1][2] = 9;
	
}
void input()
{
	cin >> N >> M;
	char c;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			if (c <= '9') c = c - '0';
			else c = c - 'A' + 10; // A만큼 빼고 10을 더하면 바로 십진수로 바꿀수 있음
			for (int k = 0; k < 4; k++)
			{
				Code[i][j * 4 + k] = HexToBin[c][k]; // Code의 j*4번째(한번 입력할때마다 4개씩 입력하므로)에
			}											// 변환된 2진수코드 입력
		}
	}
}
void Solution()
{
	int AnswerIndex = 7;
	int AnswerArray[8] = { 0, };
	
	for (int i = 1; i < N; i++)
	{
		for (int j = M * 4 - 1; j >= 0; j--)
		{
			int Min = 0, Part[3] = { 0, };
			if (Code[i][j] == 1 && Code[i - 1][j] == 0) // 중복 방지를 위해 위가 0일때만 수행(같은 암호에 대해 총 1번만 수행)
			{
				while (Code[i][j] == 1) { Part[2]++; j--; } // 1번 수행할때마다 인덱스가 1 감소되는 효과와 같으므로 j--
				while (Code[i][j] == 0) { Part[1]++; j--; } // 순서가 0,1,0,1인데 뒤부터 시작하므로 1, 다음 0, 다음 1
				while (Code[i][j] == 1) { Part[0]++; j--; } // 마지막은 어차피 0으로 끝나고 마지막 결과와 상관없이 구할 수 있음
				j++;
				Min = Part[2]; // 비율을 구하려면 각각을 최소 수치로 나눠야하므로 최소값 필요
				Min = (Min > Part[1]) ? Part[1] : Min;
				Min = (Min > Part[0]) ? Part[0] : Min; // 최소값 구하기

				for (int k = 0; k < 3; k++) 
					Part[k] /= Min; // 나누기
				AnswerArray[AnswerIndex--] = Ten[Part[0]][Part[1]][Part[2]]; // 아까 저장한 십진수 넣기
				if (AnswerArray[AnswerIndex + 1] == -1)
				{
					Answer = 0; return; // 답이 없음
				}
				if (AnswerIndex == -1) // -1이면 8번 수행했다는 뜻
				{
					int Value = (AnswerArray[0]+AnswerArray[2]+AnswerArray[4]+AnswerArray[6]) * 3 + 
						AnswerArray[1]+AnswerArray[3]+AnswerArray[5]+AnswerArray[7];
					if (Value % 10 == 0)
					{
						for (int i = 0; i < 8; i++) Answer = Answer + AnswerArray[i];
					}
					AnswerIndex = 7;

				}
			}
		}
	}
}
void Solve()
{
	SettingCode();
	int Tc;
	cin >> Tc;
	for (int i = 1; i <= Tc; i++)
	{
		Answer = 0;
		input();
		Solution();
		cout << "#" << i << " " << Answer << "\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	Solve();
}