#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <iostream>
#define pii pair<int,int>
#define SIZE 102
#define R first
#define C second
using namespace std;
int board[SIZE][SIZE];
vector <pii> robots[SIZE];
pii curRobots[SIZE];
int robotsIndex[SIZE];
int X=0,answer=0;
void init(vector<vector<int>>& points, vector<vector<int>>& routes) {
    for (int i=0; i<X; i++) {
        for(auto cur : routes[i]) {
            robots[i].push_back({points[cur-1][0], points[cur-1][1]});
        }
        auto cur = robots[i][0];
        curRobots[i] = cur;
        robotsIndex[i] = 1;
        
    }
}
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    X = routes.size();
    init(points,routes);
    for(int time=0; ; time++) {
        // 0초 = 설정
        
        // 1. 충돌 확인(0초부터 하기)
        for (int i=0; i<X; i++) {
            auto cur = curRobots[i];
            int cr = cur.R;
            int cc = cur.C;

            if(cr == -1 && cc == -1) continue;
            board[cr][cc]++;
            if(robotsIndex[i] == robots[i].size()) {
                curRobots[i] = {-1,-1};
            }
        }
        // 2. 출발하자마자 도착 X, 위치 이동하기
        // 이미 도착한 경우/아직 도착 X, 이미 도착 -> nxt가 없는 경우 / 있는 경우
        for (int i=0; i<X; i++) {
            auto cur = curRobots[i];
            int cr = cur.R;
            int cc = cur.C;
            if(cr == -1 && cc == -1) continue;
            int nxtIndex = robotsIndex[i];
            auto nxt = robots[i][robotsIndex[i]];
            int nr = nxt.R;
            int nc = nxt.C;
            if(cr - nr < 0) cr++;
            else if (cr - nr > 0) cr--;
            else {
                if(cc - nc < 0) cc++;
                else if (cc - nc > 0) cc--;   
            }
            curRobots[i] = {cr,cc};
            if(cr == nr && cc == nc) {
                robotsIndex[i]++;
            }
        }
        
        for(int i=0; i<SIZE; i++) {
            for (int j=0; j<SIZE; j++) {
                if(board[i][j] > 1) answer++;
                board[i][j]=0;
            }
        }
        bool flag=true;
        
            for (int i=0; i<X; i++) {
            // cout << " time : " << time << " i : " << i << "robotsIndex[i] : " << robotsIndex[i] << "\n";
            if(robotsIndex[i] != robots[i].size()) {
                flag = false; 
                 break;
            }
        }
        if(flag) break;
    }
    
     for (int i=0; i<X; i++) {
            auto cur = curRobots[i];
            int cr = cur.R;
            int cc = cur.C;

            if(cr == -1 && cc == -1) continue;
            board[cr][cc]++;
            if(robotsIndex[i] == robots[i].size()) {
                curRobots[i] = {-1,-1};
            }
        }
    
        for(int i=0; i<SIZE; i++) {
            for (int j=0; j<SIZE; j++) {
                if(board[i][j] > 1) answer++;
                board[i][j]=0;
            }
        }
    return answer;
}