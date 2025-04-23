#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define SIZE 100002
int N,res=SIZE;
void binSearch(int l,int r, vector<int>& diffs, vector<int>& times, long long limit) {
    if(l > r) return;
    if(l < 1) return;
    int mid = (l+r)/2;

    long long curLimits=times[0];
    for (int i=1; i<N; i++) {
        int diff = diffs[i];
        int time_cur = times[i];
        int time_prev = times[i-1];
        if(diff > mid)
        curLimits += (diff - mid) * (time_cur + time_prev);
        curLimits += time_cur;
    }
         if(curLimits <= limit) {
            res = min(mid,res);
            binSearch(l,mid-1,diffs,times,limit);
        } else {
         binSearch(mid+1,r,diffs,times,limit);
    } return;
}
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    N=diffs.size();
    int maxValue = -1;
    for (auto i : diffs)
        maxValue = max(maxValue,i);
    binSearch(1,maxValue,diffs,times,limit);
    answer = res;
    return answer;
}