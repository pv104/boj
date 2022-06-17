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
			else c = c - 'A' + 10; // A��ŭ ���� 10�� ���ϸ� �ٷ� �������� �ٲܼ� ����
			for (int k = 0; k < 4; k++)
			{
				Code[i][j * 4 + k] = HexToBin[c][k]; // Code�� j*4��°(�ѹ� �Է��Ҷ����� 4���� �Է��ϹǷ�)��
			}											// ��ȯ�� 2�����ڵ� �Է�
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
			if (Code[i][j] == 1 && Code[i - 1][j] == 0) // �ߺ� ������ ���� ���� 0�϶��� ����(���� ��ȣ�� ���� �� 1���� ����)
			{
				while (Code[i][j] == 1) { Part[2]++; j--; } // 1�� �����Ҷ����� �ε����� 1 ���ҵǴ� ȿ���� �����Ƿ� j--
				while (Code[i][j] == 0) { Part[1]++; j--; } // ������ 0,1,0,1�ε� �ں��� �����ϹǷ� 1, ���� 0, ���� 1
				while (Code[i][j] == 1) { Part[0]++; j--; } // �������� ������ 0���� ������ ������ ����� ������� ���� �� ����
				j++;
				Min = Part[2]; // ������ ���Ϸ��� ������ �ּ� ��ġ�� �������ϹǷ� �ּҰ� �ʿ�
				Min = (Min > Part[1]) ? Part[1] : Min;
				Min = (Min > Part[0]) ? Part[0] : Min; // �ּҰ� ���ϱ�

				for (int k = 0; k < 3; k++) 
					Part[k] /= Min; // ������
				AnswerArray[AnswerIndex--] = Ten[Part[0]][Part[1]][Part[2]]; // �Ʊ� ������ ������ �ֱ�
				if (AnswerArray[AnswerIndex + 1] == -1)
				{
					Answer = 0; return; // ���� ����
				}
				if (AnswerIndex == -1) // -1�̸� 8�� �����ߴٴ� ��
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