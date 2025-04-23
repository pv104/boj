#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[5],res,N;
void rec(int k,int idx, vector<vector<int>>& q, vector<int>& ans) {

    if(k == 5) {
        for(int i=0; i<q.size(); i++) {
            int cnt=0;
            for (int j=0; j<5; j++) {
                for (int l=0; l<5; l++) {
                   if(q[i][j] == arr[l]) {
                    cnt++; break;
                }  
                }
               
                }
            
            if(cnt != ans[i]) return;
            }
        
        res++; return;
    }
    if(idx > N) return;
    for (int i=idx; i<=N; i++) {
        arr[k] = i;
        rec(k+1,i+1,q,ans);
    }
    return;
}
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    N = n;
    rec(0,1,q,ans);
    int answer = res;
    return answer;
}