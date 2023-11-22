#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
#define ll long long
vector <ll> v;
int solution(int n, int k) {

    int answer = 0;
    string s = "";
    while (n != 0) {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());
    int len = s.length();
    string t = "";
    for (auto i : s) {
        if (i == '0') {
            if (t != "")
            {
                if (stol(t) >= 2)
                    v.push_back(stol(t));
                t = "";
            }
        }
        else
            t += i;
    }
    if (t != "" && stol(t) >= 2)
        v.push_back(stol(t));
    for (int i = 0; i < v.size(); i++) {
        for (int j = 2; j <= sqrt(v[i]); j++) {
            if (v[i] % j == 0) {
                v[i] = 0;
                break;
            }
        }
        if (v[i] != 0) answer++;
    }
    return answer;
}