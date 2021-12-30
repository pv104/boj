#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int ll;
string mem[105][105];
string BigInteger(string s1, string s2)
{
	int n1 = 0, n2 = 0;
	int sum = 0;
	string result = "";
	while (!(s1.empty() && s2.empty() && sum == 0))
	{
		if (!(s1.empty()))
		{
			n1 = s1.back() - '0';
			s1.pop_back();
		}
		if(!(s2.empty())) 
		{ 
			n2 = s2.back() - '0';
			s2.pop_back();
		}sum += (n1 + n2);
		result += to_string(sum % 10);
		sum /= 10;
		n1 = 0, n2 = 0;
	}
	reverse(result.begin(), result.end());
	return result;
}

string Pascal(int n, int m)
{

	if (n < 0 || m < 0) return "";
	if (n == m || m == 0) 
	{
		mem[n][m] = "1";
		return "1";
	}
	if (!mem[n][m].empty()) return (mem[n][m]);

	else
	{
		mem[n][m] = BigInteger(Pascal(n - 1, m - 1),Pascal(n - 1, m));
	}
	return mem[n][m];
}
int main()
{
	int n = 0, m = 0;
	string res;
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	res = BigInteger(to_string(n),to_string(m));
	res = Pascal(n, m);
	cout << res;
}
