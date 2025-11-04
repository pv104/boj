import java.io.*;
class Solution {
    
    static int N = 3;
    static int ans;
    static int[][] A = new int[N][N], B = new int[N][N];
    static boolean isEqual() {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if(A[i][j] != B[i][j]) return false;
            }
        }
        return true;
    }
    static boolean isEnd() {
        boolean flag = false;
        // 가로 3행, 세로 3열
        for (int i=0; i<N; i++) {
            int t = A[i][0],cnt=0;
            for (int j=0; j<N; j++) {
                if(t > 0 && t == A[i][j]) cnt++;
            }
            if(cnt == N) flag = true;
            t = A[0][i]; cnt=0;
            
            for (int j=0; j<N; j++) {
                if(t > 0 && t == A[j][i]) cnt++;
            }
            if(cnt == N) flag = true;
        }
        flag = flag | (A[0][0] > 0 && A[0][0] == A[1][1] && A[1][1] == A[2][2]);
        flag = flag | (A[0][2] > 0 && A[0][2] == A[1][1] && A[1][1] == A[2][0]);
        
        return flag;
    }
    static void rec(int t, int f, int cnt) {
        if(ans == 1) return;
        if(cnt > N*N) return;

        if(isEqual()) {
            ans = 1; return;
        } 
        if(isEnd()) return;
        if(f == 0) {
            for (int i=0; i<N*N; i++) {
            if(A[i/3][i%3] == 0){
            A[i/3][i%3] = f+1;
            rec(i+1,1,cnt+1);
            A[i/3][i%3] = 0;
            }
        }
        } else if(f == 1) {  
         for (int i=0; i<N*N; i++) {
            if(A[i/3][i%3] == 0) {
            A[i/3][i%3] = f+1;
            rec(i+1,0,cnt+1);
            A[i/3][i%3] = 0;
            }
        }
    } 
}
    
    
    public static void solve() {
        rec(0,0,0);
    }
    public int solution(String[] board) {
        int answer = -1;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                char c = board[i].charAt(j);
                int t = 0;
                if(c == 'O') t = 1;
                else if(c == 'X') t = 2;
                B[i][j] = t;
            }
        }
        solve();
        answer = ans;
        return answer;
    }
}