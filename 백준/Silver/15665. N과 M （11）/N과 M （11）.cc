#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
int arr[10], dat[10];
bool isused[10];
int n, m;
int cnt;
map < string, int > res;
bool cmp(pair <string, int>& a, pair <string, int>& b)
{
	if (a.second < b.second) return true;
	else return false;
}
void Permutation(int k)
{
	if (k == m)
	{
		string s = "";
		for (int i = 0; i < m; i++)
		{
			s += to_string(arr[i]) + ' ';
		}

		int t = res.size();
		res.insert({ s, cnt++});
		if (t == res.size())
			cnt--;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		arr[k] = dat[i];
		Permutation(k + 1);
	}
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> dat[i];
	sort(dat, dat + n);

	Permutation(0);
	vector < pair<string, int>> v(res.begin(), res.end());
	sort(v.begin(), v.end(), cmp);

	for (auto i : v)
		cout << i.first << "\n";
}