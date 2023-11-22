#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 11
using namespace std;
int res = 0, Count = INT32_MAX;
int arrows[MAX];
int result[MAX], counts[MAX];
int selected[MAX];
void solve(int cnt, int k, int cur, vector<int>& info) {
    if (cnt == k) {
        int t = 0;
        int apeachSum = 0;
        int val = 10;
        int sum = 0;
        // cout << " res : ";
        for (int i = 0; i < MAX; i++) {
            // cout << result[i] << ' ';
            if ((info[i] == 0) && (result[i] == 0)) {
                val--;
                continue;
            }
            if (info[i] < result[i])
                t += (val);
            else if ((info[i] > 0) && (info[i] >= result[i]))
                apeachSum += (val);
            val--;
        }
        // cout << "\n";
        sum = t - apeachSum;
        if (sum <= 0) return;

        if (res == sum) {
            res = sum;

            int val = 10;
            int countsSum = 0;
            for (int i = 0; i < MAX; i++)
            {
                countsSum += (val-- * result[i]);
            }
            if (Count > countsSum)
            {

                for (int i = 0; i < MAX; i++)
                {
                    selected[i] = result[i];
                }
                Count = countsSum;
            }
        }
        else if(res < sum) {
            res = sum;

            int val = 10;
            int countsSum = 0;
            for (int i = 0; i < MAX; i++)
            {
                selected[i] = result[i];
                countsSum += (val-- * result[i]);
            }
            Count = countsSum;
            }
        return;
    }
    for (int i = cur; i < MAX; i++) {
        result[i]++;
        solve(cnt + 1, k, i, info);
        result[i]--;
    }
    return;
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    int cnt = 0;
    for (int i = 0; i < MAX; i++)
        arrows[i] = i;
    cnt = 0;
    solve(0, n, 0, info);
    int ans = 0;
    for (int i = 0; i < MAX; i++) {
        ans += selected[i];
    }
    if (ans == 0)
    {
        answer.push_back(-1);
    }
    else
    {
        for (int i = 0; i < MAX; i++)
        {
            answer.push_back(selected[i]);
        }
    }
    return answer;
}