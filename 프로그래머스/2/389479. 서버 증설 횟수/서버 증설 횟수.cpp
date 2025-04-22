#include <string>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define S first
#define T second
queue <pii> q;
int curServer=0;
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    for (int time=0; time<24; time++) {
        
        if(!q.empty()) {
            if(q.front().T == time) {
                curServer -= q.front().S;
                q.pop();
            }
        }
        int p = players[time];
        if (p < curServer * m + m) continue;
        int adds = (p - curServer * m) / m;
        curServer += adds;
        answer += adds;
        q.push({adds,time+k});
        
    }
    return answer;
}