#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio cin.tie(0); cin.sync_with_stdio(0)
#define SIZE 5003
#define INF 10000000000
long long cur = INF, N;
vector<long long> arr;
struct res {
	long long f, s, t;
	res() {};
	res(long long f, long long s, long long t) {this->f = f; this->s = s; this->t = t; }
};
res result[SIZE];
void init() {
}
void input() {

	cin >> N;
	long long t = 0;
	for (long long i = 0; i < N; i++)
	{
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
}
long long solve(const long long &unable) {
	for (long long i = 0, j = N - 1; ;)
	{
		if (i == j) break;
		if (i == unable) {
			++i; continue;
		}
		else if (j == unable) {
			--j; continue;
		}
		long long t = arr[unable] + arr[i] + arr[j];
		if (cur > abs(t)) {
			cur = abs(t);
			result[unable].f = arr[i];
			result[unable].s = arr[unable];
			result[unable].t = arr[j];
		}
		if (t < 0) i++;
		else j--;
	}
	return cur;
}
int main() {
	fastio;
	init();
	input();
	long long zero = INF;
	long long idx = 0;
	for (long long i = 0; i < N; i++)
	{

		long long temp = solve(i);
		if (zero > temp)
		{
			zero = temp;
			idx = i;
		}
	}
	vector<long long> print;
	
		print.push_back(result[idx].f);
		print.push_back(result[idx].s);
		print.push_back(result[idx].t);
		sort(print.begin(), print.end());
		for (auto i : print)
			cout << i << ' ';
	
}