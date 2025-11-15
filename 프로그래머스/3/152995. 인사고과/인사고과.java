import java.io.*;
import java.util.*;
class Solution {
    
    static class Pair  {
        int a,b,sum;
        Pair() {}
        Pair(int a1,int b1,int sum1) {
            a=a1;
            b=b1;
            sum=sum1;
        }
    }
    static final int N_SIZE = 100002,LEN = 100000;
    static int N;
    static int[] dp = new int[N_SIZE], maxA = new int[N_SIZE],cnts = new int[N_SIZE*2];
    static int ta,tb;
    static PriorityQueue<Pair>[] A = new PriorityQueue[N_SIZE*2];
    static Comparator<Pair> cmp = Comparator.comparingInt((Pair p) -> -p.sum)
        .thenComparingInt(p -> -p.a)
        .thenComparingInt(p -> p.b);
    
    static int solve(int[][] scores) {
        dp[N] = maxA[N];
        for (int i=LEN-1; i>=0; i--) {
            dp[i] = Math.max(dp[i+1],maxA[i]); // 둘중 큰거
        }
        int cnt=0;
        // for (int i=0; i<=8; i++) {
        //     System.out.println(" dpi, maxA" + " " + i + " " + dp[i] + " " + maxA[i]);
        // }
        cnt=1;
        int eq=0;
        int idx=200000;
        while(idx > 0) {
            while(!A[idx].isEmpty()) {
                Pair cur = A[idx].poll();
                if(cur.a == ta && cur.b == tb) {
                    if(cur.b < dp[cur.a+1]) return -1;
                    return cnt;
                } else {
                     if(cur.b < dp[cur.a+1]) continue;
                    eq++;
                }
            }
            idx--;
            cnt += eq;
            eq =0;
            // 동석차 처리
            // 동석차 처리중이라면, cnt에 더하지 말기
        }
        return cnt;
    }
    public int solution(int[][] scores) {
        N = scores.length;
        for (int i=0; i<N_SIZE*2; i++)
            A[i] = new PriorityQueue<Pair>(cmp);
        for (int i=0; i<N; i++) {
            int a = scores[i][0];
            int b = scores[i][1];
            // maxA[i]에서 b의 최대값
            maxA[a] = Math.max(maxA[a],b);
            cnts[a+b]++;
            A[a+b].add(new Pair(a,b,a+b));
        }
        ta = scores[0][0];
        tb = scores[0][1];
        int answer = solve(scores);
        return answer;
    }
}