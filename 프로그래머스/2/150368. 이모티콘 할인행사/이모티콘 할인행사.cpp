#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000005
#define PERCENT 0
#define DISCOUNT 1
pair<int, int> res;
int selected[9];
int mul[9];
void PMT(int m,int cnt, vector<vector<int>>& users, vector<int> &emoticons) {
    if (m == cnt) {
        pair<int, int> t;
        int price = 0;
        for (auto user : users)
        {
            for (int i = 0; i < m; i++) {
                if(user[0] <= selected[i])
                t.second += (mul[i] = (int(emoticons[i]) / 100 * (100 - int(selected[i]))));
            }
            if (user[1] <= t.second) {
                t.first++;
            }
            else
                price += t.second;
            t.second = 0;
        }
        if (res.first < t.first)
        {
            res.first = t.first;
            res.second = price;
        }
        if (res.first == t.first) {
            res.second = max(price, res.second);
        }
        return;
    }
    // [0]=10,[1]=10,[2]=10...[n]
    for (int i = 10; i <= 40; i+=10) {
        selected[cnt] = i;
        PMT(m, cnt + 1, users, emoticons);
    }
    return;
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    PMT(emoticons.size(), 0, users, emoticons);
    vector<int> answer;
    answer.push_back(res.first);
    answer.push_back(res.second);
    return answer;
}