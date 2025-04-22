#include <string>
#include <vector>
#include <set>
#include <queue>
#include <memory.h>
#include <iostream>
#define pii pair<int,int>
#define SIZE 52
#define LEN 102
using namespace std;
set <pii> s[26];
char board[SIZE][SIZE];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
bool visited[SIZE][SIZE];
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int N = storage.size();
    int M = storage[0].length();
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            board[i][j] = storage[i][j];
            s[board[i][j]-'A'].insert({i,j});
        }
    }
    for (auto cur : requests) {
        if(cur.length() == 1) {
            for (int r=0; r<N; r++) {
                for (int c=0; c<M; c++) {
                    if(board[r][c] == cur[0]) {
                        queue <pii> q;
                        memset(visited,false,sizeof(visited));
                        q.push({r,c});
                            while(!q.empty()) {
                                int y = q.front().first;
                                int x = q.front().second;
                                q.pop();
                                if(y == 0 || y == N-1 || x == 0 || x == M-1) {
                                    // cout << "cur : " << cur[0] << " size : " << s[cur[0] - 'A'].size();
                                    s[cur[0] - 'A'].erase({r,c});
                                    // cout << " after size : " << s[cur[0] - 'A'].size() << "\n";
                                    break;
                                }
                                for (int dir=0; dir<4; dir++) {
                                    int ny = y+dy[dir];
                                    int nx = x+dx[dir];
                                    if(board[ny][nx] != '0' || visited[ny][nx]) continue;
                                    visited[ny][nx] = true;
                                    q.push({ny,nx});
                                            }
                        } 
                    }
                }
            }
            for (int i=0; i<N; i++) {
                for (int j=0; j<M; j++) {
                    
                    if(cur[0] == board[i][j]) board[i][j] = '0';
                }
            }
            for (auto sets : s[cur[0] - 'A']) {
                board[sets.first][sets.second] = cur[0];
            }
        } else {
            // cout << " 2 cur : " << cur[0] << "\n";
            s[cur[0] - 'A'].clear();
            for (int i=0; i<N; i++) {
                for (int j=0; j<M; j++) {
                    
                    if(cur[0] == board[i][j]) board[i][j] = '0';
                }
            }
        }
    }
    
    for (auto k : s) {
        answer += k.size();
    }
    return answer;
}