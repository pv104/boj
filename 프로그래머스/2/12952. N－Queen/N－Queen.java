import java.util.*;
import java.io.*;

class Solution {
    static final int SIZE = 15;
    static boolean[] usedLeft = new boolean[SIZE<<1], usedCol = new boolean[SIZE], usedRight = new boolean[SIZE<<1];
    static int answer = 0,N;
    static void rec(int idx) {
            if(idx == N) {  
            answer++; 
            return;
        }
        for (int nxt=0; nxt<N; nxt++) {
            if(usedCol[nxt] || usedLeft[idx+nxt] || usedRight[idx-nxt+N-1]) continue;
            usedCol[nxt] = usedLeft[idx+nxt] = usedRight[idx-nxt+N-1] = true;
               rec(idx+1);
            usedCol[nxt] = usedLeft[idx+nxt] = usedRight[idx-nxt+N-1] = false;
        }
    }
               
               
    public int solution(int n) {
        N = n;
        rec(0);
        return answer;
    }
}