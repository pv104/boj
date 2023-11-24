#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 100005
using namespace std;
int totalD, totalP;
int idxD, idxP;
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    for (int i = 0; i < n; i++) {
        totalD += deliveries[i];
        totalP += pickups[i];
    }
    // 2,1,3,0,1 / 0,4,0,3,0
    reverse(deliveries.begin(), deliveries.end());
    reverse(pickups.begin(), pickups.end());
    // answer+=max(n-idxD,n-idxP)*2;
    
    while ((totalD != 0) || (totalP != 0)) {

        int nowCap = cap;
        int val = 0;
        if (totalD < cap) nowCap = totalD; // deli 하고, 
        while (nowCap != 0) {
            if (idxD >= n) break;
        if (deliveries[idxD] > 0) {
            
                // 안가도 됨
                if (deliveries[idxD] <= nowCap) {
                    nowCap -= deliveries[idxD];
                    totalD -= deliveries[idxD];
                    deliveries[idxD] = 0;
                }
                else {
                    deliveries[idxD] -= nowCap;
                    totalD -= nowCap;
                    nowCap = 0;
                }
                val = max(val, n - idxD);
            }

        else
            idxD++;
        }
        nowCap = min(totalP, cap);
        while (nowCap != 0) {
            if (idxP >= n) break;
        if (pickups[idxP] > 0) {
           
            if (pickups[idxP] <= nowCap) {
                nowCap -= pickups[idxP];
                totalP -= pickups[idxP];
                pickups[idxP] = 0;
            }
            else {
                pickups[idxP] -= nowCap;
                totalP -= nowCap;
                nowCap = 0;
            }
                val = max(val, n - idxP);
            }
        else
            idxP++;
        }
        answer += val * 2;
    }
    return answer;
}