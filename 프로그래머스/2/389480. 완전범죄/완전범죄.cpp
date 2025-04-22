#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 42
#define SIZE 125
#define INF 987654321
int dp[MAX][SIZE];
int solution(vector<vector<int>> info, int n, int m) {
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<SIZE; j++)
            dp[i][j]=INF;
    }
    for (int i=0; i<SIZE; i++) {
        dp[0][i] = 0;
    }
    for (int k=0; k<info.size(); k++) {
        
        int a = info[k][0];
        int b = info[k][1];
        // cout << " k : " << k << " a : " << a << " b : " << b << " dp[k+1][b] : " << dp[k+1][b] << "\n";
        
        for (int i=0; i<m; i++) {
            if(dp[k][i] == INF) continue;
            // a
            if(dp[k][i]+a < n)
            dp[k+1][i] = min(dp[k+1][i],dp[k][i]+a);
            // cout << " dp[k+1][i] " << dp[k+1][i];
            // b
            if(b+i < m)
            dp[k+1][b+i] = min(dp[k+1][b+i],dp[k][i]);
            // cout << " dp[k+1][b+i] : " << dp[k+1][b+i] << " b : " << b << " i : " << i << "\n";
        }
    }
    int answer = INF;
    for(int i=0; i<m; i++) {
        answer = min(answer,dp[info.size()][i]);
    }
    
    return answer == INF ? -1 : answer;
}