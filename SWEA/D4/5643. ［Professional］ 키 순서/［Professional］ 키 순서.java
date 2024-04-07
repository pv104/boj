import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
 
public class Solution {
 
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N,M;
    static int board[][];
    static int rowCnt[], colCnt[];
    static final int INF = 987654321;
    static void input() throws Exception {
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        board = new int[N+1][N+1];
        rowCnt = new int[N + 1];
        colCnt = new int[N + 1];        
        for (int i=0; i<=N; i++)
            Arrays.fill(board[i],INF);
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            board[r][c] = 1;
        }
    }
   
    static int solve() throws Exception {
    	  for (int k = 1; k <= N; k++) {
              for (int i = 1; i <= N; i++) {
                  for (int j = 1; j <= N; j++) {
                      board[i][j] = Math.min(board[i][j], board[i][k] + board[k][j]);
                  }
              }
          }
    	  for (int i = 1; i <= N; i++) {
              for (int j = 1; j <= N; j++) {
                  if (i == j || board[i][j] == INF) continue;
                  ++rowCnt[i];
                  ++colCnt[j];
              }
          }
    	  int res=0;
    	  for (int i = 1; i <= N; i++) {
              if (rowCnt[i] + colCnt[i] == N - 1) res++;
          }
    	  return res;
      }

    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(br.readLine());
        for (int i = 1; i <= T; i++) {
             
            input();
            sb.append("#").append(i).append(" ").append(solve()).append("\n");
        }
        System.out.print(sb);
    }
     
}