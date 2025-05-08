import java.util.*;
class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {0,0};
        int val=0,minCnt=987654321,cnt=0,i=0,j=0;
        
        int N = sequence.length;
        
        while(true) {
            if(val >= k && i < N) {
                if(val == k) {
                    if(minCnt > cnt) {
                        minCnt = cnt;
                    answer[0] = i;
                    answer[1] = i+cnt-1;
                    }
                }
                val-=sequence[i++];
                cnt--;
            }
            else if (val < k && j < N){
                val+=sequence[j++];
                cnt++;
            }
            else break;
        }
        return answer;
    }
}