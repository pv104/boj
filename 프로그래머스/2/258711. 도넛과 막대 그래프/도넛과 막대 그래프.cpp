#include <bits/stdc++.h>
#define SIZE 1000002
#define pii pair<int,int>
#define DONUT 1
#define STICK 2
#define EIGHT 3
using namespace std;
vector<int> board[SIZE];
int in[SIZE];
bool visited[SIZE];
// 1.진출차수 계산하기
int findOut(vector<vector<int>>& edges) {
    for (auto i : edges) {
        int a = i[0];
        int b = i[1];
        board[a].push_back(b);
        in[b]++;
    }
    int maxOut = 0;
    int idx = 1;
    for (int i=1; i<SIZE; i++) {
        if(in[i] == 0 && maxOut < board[i].size()) {
            idx = i;
            maxOut = board[i].size();
        }
    }
    return idx;
}
int bfs(int start) {
    queue <int> q;
    int maxSize = 0;
    bool isDonut = false;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto nxt : board[cur]) {
       
            if(visited[nxt]) continue;
            if(nxt == start && board[nxt].size() > 0) isDonut = true;
            maxSize = max(maxSize,(int)board[nxt].size());
            visited[nxt] = true;
            q.push(nxt);
       }
    }
    if(isDonut) {
        if(maxSize == 1) {
            return DONUT;
        }
        return EIGHT;
    } else return STICK;
}

vector<int> solution(vector<vector<int>> edges) {
    memset(visited,false,sizeof(visited));
    vector<int> result(4);
    int creates = findOut(edges);
    for(auto start : board[creates]) {
        int t = bfs(start);
        result[t]++;
    }
    result[0] = creates;
    return result;
    
}