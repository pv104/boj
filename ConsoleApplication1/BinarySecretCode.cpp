#include <bits/stdc++.h>
using namespace std;
#define MAXDIGITS 10
#define MAXCOLUMNS 56
#define MAXARRAYROWS 51
#define MAXARRAYCOLUMNS 101
int compare[MAXDIGITS];
int CorrectCode[MAXDIGITS][7] =
{
	{0,0,0,1,1,0,1},
	{0,0,1,1,0,0,1},
	{0,0,1,0,0,1,1},
	{0,1,1,1,1,0,1},
	{0,1,0,0,0,1,1},
	{0,1,1,0,0,0,1},
	{0,1,0,1,1,1,1},
	{0,1,1,1,0,1,1},
	{0,1,1,0,1,1,1},
	{0,0,0,1,0,1,1}
};
int findIndex(string temp) // 1�� �ִ� ������ ��ġ�� �ڿ������� ã�Ƽ� �ε��� ��ȯ
{
	for (int i = temp.length(); i >= 0; i--)
	{
		if (temp[i] == '1')
		{
			return i;
		}

	}
	return -1;
}
string Convert(string temp, int index) // temp���� 0���� �е��� �κ� �ڸ��� reverse�ؼ� ��ȯ
{
	string tempstring = "";
	for (int j = index; j > (index - 56); j--)
	{
		tempstring += temp[j];
	}

	reverse(tempstring.begin(), tempstring.end()); // tempstring�� reverse�� ��� ���� -> �ڵ常 ������
	return tempstring;

}
int Compare(vector <int>& CompareCode) // ��ȣ�ڵ尡 �������� ������ ��ȯ
{
	bool flag = true;
	for (int i = 0; i < 10; i++)
	{
			for (int j = 0; j < 7; j++)
			{
				if ((CorrectCode[i][j] ^ CompareCode[j]))
					flag = false;
			}
		
		if (flag) return i;
		flag = true;
	}

	return -1;
}
int solve(int& sum,string tstring)
{
	vector <vector<int>> Code;
	vector <int> tv,result;
	bool flag = true;
	int odd = 0, even = 0, chk = 0,res = 0, tsum = 0;
	for (int i = 0; i < 8; i++)
		Code.push_back(tv);
	for (int j = 0; j < 56; j++)
	{
		if (j > 0 && (j % 7 == 0)) chk++;
		Code[chk].push_back(tstring[j] - '0');
	}

	for (int i = 0; i < 8; i++)
	{
		result.push_back(Compare(Code[i]));
		tsum += result[i];
	}

	for (int i = 0; i < result.size(); i++)
	{
		res += result[i];
		if (i % 2 == 0)
			odd += result[i];
		else even += result[i];
	}

	if (((odd * 3) + even) % 10 == 0)
	{
		sum = tsum; return res;
	}
	else return -1;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	int t, n, m, index = 0, res = 0, tmp = 0, tsum = 0;
	bool flag = false;
	string temp, tempstring = "";
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			index = findIndex(temp);
				if (index != -1)
				{	
					tempstring = Convert(temp, index);
					tmp = solve(tsum,tempstring);
					if (tmp == tsum) res = tmp;
				}
			
		}

		if (res == -1) res = 0;
		cout << "#" << tc << " " << res << "\n";
		flag = false;
		tempstring = "";
		res = 0;

	}
	return 0;
}