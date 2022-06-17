#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <sstream>
using namespace std;
#define MAX 100005
int t, n;
deque <int> dq;
string p, str, strbuffer;
void input()
{
	cin.ignore();
	cin >> p >> n >> str;

}
void preProcess()
{
	if (n < 1) return;
	istringstream ss(str); // [1,2,3,4]
	getline(ss, strbuffer, '['); // 1,2,3,4]

	while (getline(ss, strbuffer, ','))
	{
		dq.push_back(stoi(strbuffer)); // 1,2,3,4
	}
	
}
string solve()
{
	bool flag = true; // true = NR, false = R
	int length = p.length();
	for (int i = 0; i < p.length(); i++)
	{
		if (p[i] == 'D' && dq.empty()) return "error";
		if (p[i] == 'R')
		{
			if (flag) flag = false;
			else flag = true;
		}
		if (p[i] == 'D')
		{
			if (flag) dq.pop_front();
			else dq.pop_back();
		}
	}

	if (dq.empty())
		return "[]";
	else
	{
		if (flag == false) reverse(dq.begin(), dq.end());
		string res = "[";
		if (dq.size() == 1)
		{
			res += to_string(dq[0]);
			return res += "]";
		}
		else
		{
			for (int i = 0; i < dq.size()-1; i++)
				res += (to_string(dq[i]) + ",");
			res += to_string(dq[dq.size() - 1]);
			return res += "]";
		}
	}
}
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		input();
		preProcess();
		cout << solve() << "\n";
		dq.clear();
	}
}