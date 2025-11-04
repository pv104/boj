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
        
        boolean flag = (A[0][0] > 0 ) && A[0][0] == A[1][1] && A[1][1] == A[2][2];
        flag = flag | (A[0][2] > 0  && (A[0][2] == A[1][1] && A[1][1] == A[2][0]));
        flag = flag | (A[0][0] > 0  && (A[0][0] == A[1][0] && A[1][0] == A[2][0]));
        flag = flag | (A[0][1] > 0  && (A[0][1] == A[1][1] && A[1][1] == A[2][1]));
        flag = flag | (A[0][2] > 0  && (A[0][2] == A[1][2] && A[1][2] == A[2][2]));
        flag = flag | (A[0][0] > 0  && (A[0][0] == A[0][1] && A[0][1] == A[0][2]));
        flag = flag | (A[1][0] > 0  && (A[1][0] == A[1][1] && A[1][1] == A[1][2]));
        flag = flag | (A[2][0] > 0  && (A[2][0] == A[2][1] && A[2][1] == A[2][2]));
        
        return flag;
    }
    static void rec(int t, int f, int cnt) {
        if(cnt > N*N) return;

        if(isEqual()) {
            if(ans == 1) return;
//           System.out.println(" t, f, cnt " + t + " " + f + " " + cnt);
//             for (int k=0; k<N; k++) {
//             for (int l=0; l<N; l++) {
//                 if(A[k][l] == 0) System.out.print('.');
//                 else if(A[k][l] == 1) System.out.print('O');
//                 else System.out.print('X');
//             }
//             System.out.println(); 
            
        
//             }
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