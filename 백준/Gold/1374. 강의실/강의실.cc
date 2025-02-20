#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define SIZE 100003
#define pii pair<int,int>
#define fileio FILE* stream; freopen_s(&stream, "input.txt", "r", stdin)
int N;
priority_queue<pii,vector<pii>,greater<pii>> st;
priority_queue<int,vector<int>,greater<int>> ed;
int curCap, maxCap, curTime;
void input() {
    cin >> N;
    int x, s, e;
    for (int i = 0; i < N; i++) {
        cin >> x >> s >> e;
        st.push({ s,e });
    }
}
int solve() {
    while (!st.empty())
    {
        pii cur = st.top(); st.pop();
        curTime = cur.first;
        
        while ((!ed.empty()) && (ed.top() <= curTime))
        {
            ed.pop();
            curCap++;
        }
        
        // 공간이 없는 경우
        if (curCap == 0) 
            maxCap++;
        else 
            curCap--;
        ed.push(cur.second);
    }
    return maxCap;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    input();
    cout << solve();
}