#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 500005
#define NUMBER 8005
#define COMP 4000
vector <long long> vec;
int n;
long long countArr[NUMBER];
void input()
{
	int t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		vec.push_back(t);
	}

}
int Cal()
{
	double res = 0;
	for (int i = 0; i < n; i++)
		res += vec[i];
	return round(res /= (double)n);
}
int Count()
{
	int cnt = 0, max_Num = 0;
	for (int i = 0; i < n; i++)
	{
		countArr[(vec[i]+COMP)]++;
	}
	int max = 0;
	for (int i = 0; i < NUMBER; i++)
	{
		max = (max < countArr[i]) ? countArr[i] : max;
	}
	for (int i = 0; i < NUMBER; i++)
	{
		if (max == countArr[i]) {
				cnt++;
				max_Num = i - COMP;
		}
		if (cnt > 1)
			return (i - COMP);
	}

	return max_Num;
}
int Range()
{
	return vec[n - 1] - vec[0];
}
int Center()
{
	sort(vec.begin(), vec.end());
	return vec[n / 2];
}
int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	input();

	cout << Cal() << "\n";
	cout << Center() << "\n";
	cout << Count() << "\n";

	cout << Range();
}