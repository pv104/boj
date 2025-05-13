import java.util.*;
class Solution {
    public static int SIZE = 52;
    public static int[][][] dp = new int[SIZE][SIZE][SIZE];
    public static int D,I,S,N,M;
    public int[] mineralsToInt = new int[SIZE];
    public static int INF = 987654321;
    public int cal(char m,int st) {
        int pick = 0, mineral = 0;
        int res=0;
        for (int i=st; i<st+5 && i<N; i++) {
            if(m == 'd') {
                ++res;
            }
            else if(m == 'i') {
                if(mineralsToInt[i] == 1)
                    res+=5;
                else ++res;
            }
            else if(m == 's') {
                if(mineralsToInt[i] == 1)
                    res+=25;
                else if(mineralsToInt[i] == 2)
                    res+=5;
                else ++res;
            }
        }
         // System.out.println(" st : " + st + "mine : " + m + " res : " + res);
        return res;
    }
    public int rec(int d,int i,int s,int st,int m) {
        if(st >= N || m == M) return 0;
        if(dp[d][i][s] != INF) return dp[d][i][s];
        
        if(d < D)
        dp[d][i][s] = Math.min(rec(d+1,i,s,st+5,m+1)+cal('d',st),dp[d][i][s]);
        if(i < I)
        dp[d][i][s] = Math.min(rec(d,i+1,s,st+5,m+1)+cal('i',st),dp[d][i][s]);
        if(s < S)
        dp[d][i][s] = Math.min(rec(d,i,s+1,st+5,m+1)+cal('s',st),dp[d][i][s]);
        // System.out.println(" d : " + d + " i : " + i + " s : " + s + " dp : " + dp[d][i][s] + "st : " + st);
        return dp[d][i][s];
    }
    public int solution(int[] picks, String[] minerals) {
        int answer = 0;
        D = picks[0];
        I = picks[1];
        S = picks[2];
        N = minerals.length;
        M = D+I+S;
        for (int i=0; i<SIZE; i++)
            for (int j=0; j<SIZE; j++)
                Arrays.fill(dp[i][j],INF);
        for (int i=0; i<N; i++) {
            if(minerals[i].equals("diamond"))
                mineralsToInt[i] = 1;
            else if(minerals[i].equals("iron"))
                mineralsToInt[i] = 2;
            else if(minerals[i].equals("stone"))
                mineralsToInt[i] = 3;
        }
        answer = rec(0,0,0,0,0);
        
        return answer;
    }
}